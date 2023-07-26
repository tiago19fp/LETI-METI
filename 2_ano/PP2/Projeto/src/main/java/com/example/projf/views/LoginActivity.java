package com.example.projf.views;

import androidx.annotation.Nullable;
import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import android.Manifest;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;
import android.widget.Toast;


import com.example.projf.R;
import com.facebook.AccessToken;
import com.facebook.AccessTokenTracker;
import com.facebook.CallbackManager;
import com.facebook.FacebookCallback;
import com.facebook.FacebookException;
import com.facebook.GraphRequest;
import com.facebook.GraphResponse;
import com.facebook.login.LoginResult;
import com.facebook.login.widget.LoginButton;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.Arrays;


public class LoginActivity extends AppCompatActivity {

    private LoginButton loginButton;
    private CallbackManager callbackManager;
    private String email;
    private String id;
    private ArrayList<String> user;

    public static final String SHARED_PREFS = "sharedPrefs";
    public static final String TEXT = "text";
    public static final String IDFACE = "IDFACE";

    private String emailSHar;


    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        user = new ArrayList<>();
        loginButton = findViewById(R.id.login_button);

        ActivityCompat.requestPermissions(LoginActivity.this, new String[] {Manifest.permission.ACCESS_FINE_LOCATION}, 123);

        callbackManager = CallbackManager.Factory.create();
        loginButton.setReadPermissions(Arrays.asList("email","public_profile"));

        loginButton.registerCallback(callbackManager, new FacebookCallback<LoginResult>() {
            @Override
            public void onSuccess(LoginResult loginResult) {
                    //openSecAct();
            }

            @Override
            public void onCancel() {

            }

            @Override
            public void onError(FacebookException error) {

            }
        });

        loadData();
        if(!(emailSHar.equals(""))){
          openDashAct();
       }

    }

    public void saveData(){
        SharedPreferences sharedPreferences = getSharedPreferences(SHARED_PREFS, MODE_PRIVATE);
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.putString(TEXT, email);
        editor.putString(IDFACE, id);
        editor.apply();
    }

    public void loadData(){
        SharedPreferences sharedPreferences = getSharedPreferences(SHARED_PREFS,MODE_PRIVATE);
        emailSHar = sharedPreferences.getString(TEXT,"");
        id = sharedPreferences.getString(IDFACE,"");
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        callbackManager.onActivityResult(requestCode, resultCode, data);
        super.onActivityResult(requestCode, resultCode, data);
    }

    AccessTokenTracker tokenTracker = new AccessTokenTracker() {
        @Override
        protected void onCurrentAccessTokenChanged(AccessToken oldAccessToken, AccessToken currentAccessToken) {

            if(currentAccessToken==null){
                Toast.makeText(LoginActivity.this, "User logged out", Toast.LENGTH_LONG).show();
            }else{
                LoadUserProfile(currentAccessToken);
            }

        }
    };

    private  void LoadUserProfile(AccessToken newAccessToken){
        GraphRequest request = GraphRequest.newMeRequest(newAccessToken, new GraphRequest.GraphJSONObjectCallback() {
            @Override
            public void onCompleted(JSONObject object, GraphResponse response) {
                try {
                     String name = object.getString("first_name")+" "+object.getString("last_name");
                     email = object.getString("email");
                     String birthday = object.getString("birthday");
                     id = object.getString("id");
                     //String gender = object.getString("gender");
                     user.add(name);
                     user.add(email);
                     user.add(birthday);
                     //user.add(gender);
                     saveData();
                     openSecAct();
                } catch (JSONException e){
                    e.printStackTrace();
                }

            }
        });
        Bundle param = new Bundle();
        param.putString("fields","first_name,last_name,email,id,birthday,gender");
        request.setParameters(param);
        request.executeAsync();
    }

    public void openSecAct(){
        Intent intent = new Intent(this, FillSymptomsActivity.class);
        Bundle b = new Bundle();
        b.putString("id", id);
        b.putSerializable("User", user);
        intent.putExtras(b);
        startActivity(intent);
    }

    public void openDashAct(){
        Intent intent = new Intent(this, DashBoardActivity.class);
        Bundle b = new Bundle();
        b.putString("email", emailSHar);
        b.putString("id", id);
        intent.putExtras(b);
        startActivity(intent);
    }
}
