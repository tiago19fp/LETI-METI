package com.example.projf.views;

import android.content.Intent;
import android.location.Location;
import android.os.Bundle;
import android.util.SparseBooleanArray;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.example.projf.R;
import com.example.projf.controllers.GpsLocation;
import com.example.projf.interfaces.RestdbApi;
import com.example.projf.models.Sintoma;
import com.example.projf.models.User;

import java.util.ArrayList;
import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

public class FillSymptomsActivity extends AppCompatActivity implements View.OnClickListener {

    private RestdbApi restdbApi;
    private String key= "e9afd16c11a419e5a62f356a3357d0ef2e0da";
    Button b;
    private ArrayList<String> sintomas;
    private ArrayList<String> user;
    private ListView listView;
    private ArrayList<String> sintomasSelecionados;
    private ArrayAdapter<String> adapter;
    RadioGroup radioGroup;
    RadioButton radioButton;
    private String email;
    private boolean exiteUser=false;
    private String id;
    private String idFace;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        listView = findViewById(R.id.list_sintomas);

        radioGroup = findViewById(R.id.radioGroup);

        Bundle extras = getIntent().getExtras();
        user = (ArrayList<String>) extras.getSerializable("User");
        idFace = extras.getString("id");
        sintomas = new ArrayList<>();

        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl("https://appcovid19-311a.restdb.io/rest/")
                .addConverterFactory(GsonConverterFactory.create())
                .build();
        restdbApi = retrofit.create(RestdbApi.class);
        getSintomas();
        getUsers();

        b = findViewById(R.id.button_createUser);
        b.setOnClickListener(this);

        adapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_multiple_choice, sintomas);

    }

    public void checkButton(View v) {
        int radioId = radioGroup.getCheckedRadioButtonId();
        radioButton = findViewById(radioId);
    }

    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.button_createUser) {
            sintomasSelecionados = new ArrayList<>();
            SparseBooleanArray sintomaSelected = listView.getCheckedItemPositions();
            for (int i = 0; i < sintomaSelected.size(); i++) {
                int key = sintomaSelected.keyAt(i);
                boolean value = sintomaSelected.get(key);
                if (value) {
                    sintomasSelecionados.add(listView.getItemAtPosition(key).toString());
                }
            }
            if (sintomasSelecionados.isEmpty()) {
                Toast.makeText(FillSymptomsActivity.this, "Selecione um sintoma", Toast.LENGTH_LONG).show();
            } else {
                int radioId = radioGroup.getCheckedRadioButtonId();
                radioButton = findViewById(radioId);
                email = user.get(1);
                if(!exiteUser){
                createUser(sintomasSelecionados);
                exiteUser=true;
                }else{
                    updateUser(sintomasSelecionados);
                    exiteUser=false;
                }
                Intent intent = new Intent(this, DashBoardActivity.class);
                Bundle b = new Bundle();
                b.putString("email", email);
                b.putString("id", idFace);
                b.putString("idRest", id);
                intent.putExtras(b);
                startActivity(intent);
            }
        }

    }


    private void createUser(ArrayList<String> sintomas){
        GpsLocation gt = new GpsLocation(getApplicationContext());
        Location l = gt.getLocation();
        User us = new User(user.get(0),user.get(1),sintomas.toString(),String.valueOf(radioButton.getText()),String.valueOf(l.getLatitude()),String.valueOf(l.getLongitude()),user.get(2),/*user.get(3)*/"M");
        Call<User> call = restdbApi.createUser(key,us);
        call.enqueue(new Callback<User>() {
            @Override
            public void onResponse(Call<User> call, Response<User> response) {
                if(!response.isSuccessful()){
                    return;
                }
            }
            @Override
            public void onFailure(Call<User> call, Throwable t) {
            }
        });
    }

    private void getUsers(){
        Call<List<User>> call = restdbApi.getUsers(key);
        call.enqueue(new Callback<List<User>>() {
            @Override
            public void onResponse(Call<List<User>> call, Response<List<User>> response) {
                if (!response.isSuccessful()) {
                    Toast.makeText(FillSymptomsActivity.this, "code:" + response.code(), Toast.LENGTH_LONG).show();
                    return;
                }
                List<User> users = response.body();
                for (User u : users) {
                    if (u.getEmail().equals(user.get(1))) {
                        exiteUser=true;
                        id = u.getId();
                    }
                }
            }
            @Override
            public void onFailure(Call<List<User>> call, Throwable t) {
                Toast.makeText(FillSymptomsActivity.this, t.getMessage(), Toast.LENGTH_LONG).show();
            }
        });
    }

    private void updateUser(ArrayList<String> sintomas){
        User us = new User(null,null,sintomas.toString(),String.valueOf(radioButton.getText()),null,null,null,null);
        Call<User> call = restdbApi.uptadeUser(key,id,us);
        call.enqueue(new Callback<User>() {
            @Override
            public void onResponse(Call<User> call, Response<User> response) {
                if (!response.isSuccessful()) {
                    Toast.makeText(FillSymptomsActivity.this, "code:" + response.code(), Toast.LENGTH_LONG).show();
                }
            }
            @Override
            public void onFailure(Call<User> call, Throwable t) {
                Toast.makeText(FillSymptomsActivity.this, t.getMessage(), Toast.LENGTH_LONG).show();
            }
        });
    }

    private void getSintomas(){
        Call<List<Sintoma>> call = restdbApi.getSintomas(key);
        call.enqueue(new Callback<List<Sintoma>>() {
            @Override
            public void onResponse(Call<List<Sintoma>> call, Response<List<Sintoma>> response) {
                if (!response.isSuccessful()) {
                    Toast.makeText(FillSymptomsActivity.this, "code:" + response.code(), Toast.LENGTH_LONG).show();
                }
                List<Sintoma> sintomasList = response.body();
                assert sintomasList != null;
                for(Sintoma sin : sintomasList){
                    sintomas.add(sin.getSintoma());
                }
                listView.setAdapter(adapter);
            }
            @Override
            public void onFailure(Call<List<Sintoma>> call, Throwable t) {
                Toast.makeText(FillSymptomsActivity.this, t.getMessage(), Toast.LENGTH_LONG).show();
            }
        });
    }

    @Override
    protected void onStart() {
    //getUsers();
    super.onStart();
    }
}
