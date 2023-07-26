package com.example.miniprojeto_3.views;

import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProviders;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;

import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;
import com.example.miniprojeto_3.R;
import com.example.miniprojeto_3.adapters.LocationAdapter;
import com.example.miniprojeto_3.models.Forecast;
import com.example.miniprojeto_3.models.Location;
import com.example.miniprojeto_3.controllers.LocationViewModel;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

public class CitySelectorActivity extends AppCompatActivity {

    private LocationViewModel locationViewModel;
    private ArrayList<String> localNomesArray;
    private ArrayList<Forecast> fore;
    private String cidade;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final Spinner sp = findViewById(R.id.spinner);

        final Button b = findViewById(R.id.ok);

        RecyclerView r = findViewById(R.id.recycler);
        r.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.HORIZONTAL, false));
        r.setHasFixedSize(true);
        fore = new ArrayList<>();
        final LocationAdapter adapter = new LocationAdapter();
        r.setAdapter(adapter);

        localNomesArray = new ArrayList<>();

        getLocationsInfo();

        b.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                adapter.setForecasts(fore);
            }
        });

        locationViewModel = ViewModelProviders.of(this).get(LocationViewModel.class);
        locationViewModel.getAllLocations().observe(this, new Observer<List<Location>>() {
            @Override
            public void onChanged(List<Location> locations) {
                localNomesArray.clear();
                for(Location l : locations){
                    localNomesArray.add(l.getLocal());
                }

                sp.setAdapter(new ArrayAdapter<>(CitySelectorActivity.this, android.R.layout.simple_spinner_dropdown_item, localNomesArray));
            }
        });

        sp.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parentView, View selectedItemView, int position, long id) {
                cidade = localNomesArray.get(position);
                locationViewModel.getLocation(cidade).observe(CitySelectorActivity.this, new Observer<Location>() {
                    @Override
                    public void onChanged(Location location) {
                        fore.clear();
                        fore.addAll(location.getForecasts());

                    }
                });
            }

            @Override
            public void onNothingSelected(AdapterView<?> parentView) {

            }

        });


    }

    private void getLocationsInfo() {
        String url = "https://api.ipma.pt/open-data/distrits-islands.json";
        RequestQueue requestQueue = Volley.newRequestQueue(getApplicationContext());
        StringRequest stringRequest = new StringRequest(Request.Method.GET, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                try {
                    JSONObject jsonObject = new JSONObject(response);
                    JSONArray jsonArray = jsonObject.getJSONArray("data");

                    for (int i = 0; i < jsonArray.length(); i++) {
                        JSONObject local = jsonArray.getJSONObject(i);
                        ArrayList<Forecast> forecasts = new ArrayList<>();
                        Forecast forecast = new Forecast(1,1,1,"s",1,1,1,"s",1,1, "s");
                        forecasts.add(forecast);
                        locationViewModel.update(new Location(i, local.getInt("idRegiao"), local.getString("idAreaAviso"), local.getInt("idConcelho"),
                                local.getInt("globalIdLocal"), local.getDouble("longitude"), local.getInt("idDistrito"),
                                local.getString("local"), local.getDouble("latitude"),forecasts));
                        addForecasts(i, local.getInt("idRegiao"), local.getString("idAreaAviso"), local.getInt("idConcelho"),
                                    local.getInt("globalIdLocal"), local.getDouble("longitude"), local.getInt("idDistrito"),
                                    local.getString("local"), local.getDouble("latitude"));
                    }
                } catch (JSONException e) {
                    e.printStackTrace();
                }
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                error.printStackTrace();
            }
        });
        requestQueue.add(stringRequest);
    }

    private void addForecasts(final int id, final int idRegiao, final String idAreaAviso, final int idConcelho, final int globalIdLocal,
                              final double longitude, final int idDistrito, final String local, final double latitude) {
        String url = "https://api.ipma.pt/open-data/forecast/meteorology/cities/daily/"+ globalIdLocal +".json";
        //Toast.makeText(CitySelectorActivity.this, local, Toast.LENGTH_LONG).show();
        RequestQueue requestQueue = Volley.newRequestQueue(getApplicationContext());
        StringRequest stringRequest = new StringRequest(Request.Method.GET, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                try {
                    ArrayList<Forecast> forecasts;
                    forecasts = new ArrayList<>();
                    JSONObject jsonObject = new JSONObject(response);
                    JSONArray jsonArray = jsonObject.getJSONArray("data");
                    String stringer =jsonObject.getString("dataUpdate");
                    stringer = stringer.substring(11);
                    String s ="Última atualização:"+ stringer;
                    for (int i = 0; i < jsonArray.length(); i++) {
                        JSONObject cid = jsonArray.getJSONObject(i);
                         Forecast forecast = new Forecast(cid.getDouble("precipitaProb"),cid.getDouble("tMin"),cid.getDouble("tMax"), cid.getString("predWindDir"),
                                cid.getInt("idWeatherType"), cid.getInt("classWindSpeed"), cid.getDouble("longitude"),
                                cid.getString("forecastDate"), cid.getInt("classPrecInt"),cid.getDouble("latitude"), s);
                        forecasts.add(forecast);

                            locationViewModel.update(new Location(id, idRegiao,idAreaAviso,idConcelho,
                                                     globalIdLocal, longitude,idDistrito,local, latitude,forecasts));

                    }
                } catch (JSONException e) {
                    e.printStackTrace();
                }
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                error.printStackTrace();
            }
        });
        requestQueue.add(stringRequest);
    }


}

