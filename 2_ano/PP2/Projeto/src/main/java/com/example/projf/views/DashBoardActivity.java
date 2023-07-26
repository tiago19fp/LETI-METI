package com.example.projf.views;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.content.SharedPreferences;
import android.location.Address;
import android.location.Geocoder;
import android.location.Location;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.bumptech.glide.Glide;
import com.bumptech.glide.request.RequestOptions;
import com.example.projf.R;
import com.example.projf.controllers.GpsLocation;
import com.example.projf.interfaces.RestdbApi;
import com.example.projf.models.Sintoma;
import com.example.projf.models.User;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

import de.hdodenhof.circleimageview.CircleImageView;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

public class DashBoardActivity extends AppCompatActivity {

    private int infetados = 0;
    private int comSintomas = 0;
    private int semSintomas = 0;
    private int suspeitos = 0;
    private String email;
    private String latiude;
    private String longitude;
    private RestdbApi restdbApi;
    private String key = "e9afd16c11a419e5a62f356a3357d0ef2e0da";
    private ArrayList<String> userInfo;
    TextView inf;
    TextView sus;
    TextView com;
    TextView sem;
    TextView cid;
    TextView userText;
    Button button;
    private String idFace;
    private ImageView imageView;
    private String id;
    public static final String SHARED_PREFSS = "sharedPrefss";
    public static final String ID_SHARED = "id_shared";
    private String idshared;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);
        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl("https://appcovid19-311a.restdb.io/rest/")
                .addConverterFactory(GsonConverterFactory.create())
                .build();
        restdbApi = retrofit.create(RestdbApi.class);

        Bundle extras = getIntent().getExtras();
        email = extras.getString("email");
        if(extras.getString("idRest") != null){
            id = extras.getString("idRest");
            saveData();
        }

        idFace = extras.getString("id");
        imageView = findViewById(R.id.imageFace);
        loadImage();

        userInfo = new ArrayList<>();

        button = findViewById(R.id.button_altera);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
             FillActOpen();
            }
        });

        inf = findViewById(R.id.texDasInfetados);
        sus = findViewById(R.id.texDasSuspeitos);
        com = findViewById(R.id.texDasComSintomaS);
        sem = findViewById(R.id.texDasSemSintomas);
        cid = findViewById(R.id.textNomeCid);
        userText = findViewById(R.id.textUserInfo);
        loadData();
        updateUser();
        getUsers();

    }

    public void saveData(){
        SharedPreferences sharedPreferences = getSharedPreferences(SHARED_PREFSS, MODE_PRIVATE);
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.putString(ID_SHARED, id);
        editor.apply();
    }

    public void loadData(){
        SharedPreferences sharedPreferences = getSharedPreferences(SHARED_PREFSS, MODE_PRIVATE);
        idshared = sharedPreferences.getString(ID_SHARED,"");
    }

    @SuppressLint("CheckResult")
    private void loadImage(){
        String url = "https://graph.facebook.com/"+idFace+"/picture?type=normal";
        RequestOptions requestOptions = new RequestOptions();
        requestOptions.dontAnimate();
        Glide.with(DashBoardActivity.this).load(url).into(imageView);
    }

    private void FillActOpen(){
        Intent intent = new Intent(this, FillSymptomsActivity.class);
        Bundle b = new Bundle();
        b.putSerializable("User", userInfo);
        b.putString("id", idFace);
        intent.putExtras(b);
        startActivity(intent);
    }

    private void getUsers() {
        Call<List<User>> call = restdbApi.getUsers(key);
        call.enqueue(new Callback<List<User>>() {
            @SuppressLint("SetTextI18n")
            @Override
            public void onResponse(Call<List<User>> call, Response<List<User>> response) {
                if (!response.isSuccessful()) {
                    Toast.makeText(DashBoardActivity.this, "code:" + response.code(), Toast.LENGTH_LONG).show();
                    return;
                }
                List<User> users = response.body();
                for (User user : users) {
                    if (user.getEmail().equals(email)) {
                        latiude = user.getLatitude();
                        longitude = user.getLongitude();
                        userInfo.add(user.getNome());
                        userInfo.add(user.getEmail());
                        userInfo.add(user.getIdade());
                        userText.setText(user.getNome()+"\n\n"+user.getEstadoSaude());
                    }
                }
                for (User user : users) {
                    if (distance(Double.parseDouble(latiude), Double.parseDouble(longitude), Double.parseDouble(user.getLatitude()), Double.parseDouble(user.getLongitude()), 'K') <= 15) {
                        if(user.getEstadoSaude().equals("Infeção confirmada")) {
                            infetados++;
                        }else if(user.getSintomas().equals("[Sem sintomas]")) {
                            semSintomas++;
                        }else if(!user.getSintomas().equals("[Sem sintomas]")){
                            int aux = 0;
                            for (char c : user.getSintomas().toCharArray()){
                                if (c == ','){
                                    aux++;
                                }
                            }
                            if (aux >= 2) {
                                suspeitos++;
                            }
                                comSintomas++;

                        }
                    }
                }
                inf.setText(""+infetados);
                sus.setText(""+suspeitos);
                sem.setText(""+semSintomas);
                com.setText(""+comSintomas);
            }

            @Override
            public void onFailure(Call<List<User>> call, Throwable t) {
                Toast.makeText(DashBoardActivity.this, t.getMessage(), Toast.LENGTH_LONG).show();
            }
        });
    }

    private void updateUser(){
        GpsLocation gt = new GpsLocation(getApplicationContext());
        Location l = gt.getLocation();
        double la = l.getLatitude();
        double lo = l.getLongitude();
        Geocoder geocoder = new Geocoder(DashBoardActivity.this, Locale.getDefault());
        List<Address> addresses;
        try {
            addresses = geocoder.getFromLocation(la, lo, 1);
            String cityName = addresses.get(0).getLocality();
            cid.setText(cityName);
        } catch (IOException e) {
            e.printStackTrace();
        }
        User us = new User(null,null,null,null,String.valueOf(l.getLatitude()),String.valueOf(l.getLongitude()),null,null);
        Call<User> call = restdbApi.uptadeUser(key,idshared,us);
        call.enqueue(new Callback<User>() {
            @Override
            public void onResponse(Call<User> call, Response<User> response) {
                if (!response.isSuccessful()) {
                    Toast.makeText(DashBoardActivity.this, "code:" + response.code(), Toast.LENGTH_LONG).show();
                }

            }
            @Override
            public void onFailure(Call<User> call, Throwable t) {
                Toast.makeText(DashBoardActivity.this, t.getMessage(), Toast.LENGTH_LONG).show();
            }
        });
    }

    private double distance(double lat1, double lon1, double lat2, double lon2, char unit) {
        double theta = lon1 - lon2;
        double dist = Math.sin(deg2rad(lat1)) * Math.sin(deg2rad(lat2)) + Math.cos(deg2rad(lat1)) * Math.cos(deg2rad(lat2)) * Math.cos(deg2rad(theta));
        dist = Math.acos(dist);
        dist = rad2deg(dist);
        dist = dist * 60 * 1.1515;
        if (unit == 'K') {
            dist = dist * 1.609344;
        } else if (unit == 'N') {
            dist = dist * 0.8684;
        }
        return (dist);
    }

    private double deg2rad(double deg) {
        return (deg * Math.PI / 180.0);
    }

    private double rad2deg(double rad) {
        return (rad * 180.0 / Math.PI);
    }
}
