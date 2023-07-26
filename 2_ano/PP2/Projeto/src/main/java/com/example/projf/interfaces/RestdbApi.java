package com.example.projf.interfaces;

import com.example.projf.models.Sintoma;
import com.example.projf.models.User;

import java.util.List;

import retrofit2.Call;
import retrofit2.http.Body;
import retrofit2.http.GET;
import retrofit2.http.Header;
import retrofit2.http.PATCH;
import retrofit2.http.POST;
import retrofit2.http.Path;


public interface RestdbApi {

    @GET("appuser")
    Call<List<User>> getUsers(@Header("x-apikey") String xApikey);

    @GET("sintomas")
    Call<List<Sintoma>> getSintomas(@Header("x-apikey") String xApikey);

    @POST("appuser")
    Call<User> createUser(@Header("x-apikey") String xApikey, @Body User user);

    @PATCH("appuser/{id}")
    Call<User> uptadeUser(@Header("x-apikey") String xApikey, @Path("id") String id, @Body User user);

    @PATCH("appuser/{id}")
    Call<Void> deleteUser(@Header("x-apikey") String xApikey, @Path("id") String id);
}
