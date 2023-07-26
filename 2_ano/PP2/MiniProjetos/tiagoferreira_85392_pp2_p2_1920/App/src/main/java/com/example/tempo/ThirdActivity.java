package com.example.tempo;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;
import androidx.viewpager.widget.ViewPager;

import android.annotation.SuppressLint;
import android.os.Build;
import android.os.Bundle;

import com.android.volley.DefaultRetryPolicy;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.RetryPolicy;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class ThirdActivity extends AppCompatActivity {

    private ArrayList<String> s;
    private ArrayList<String> tmin1;
    private ArrayList<String> tmin2;
    private ArrayList<String> tmin3;
    private ArrayList<String> tmax1;
    private ArrayList<String> tmax2;
    private ArrayList<String> tmax3;
    private ArrayList<String> pre1;
    private ArrayList<String> pre2;
    private ArrayList<String> pre3;
    private ArrayList<String> data;
    private String id = "";

    @RequiresApi(api = Build.VERSION_CODES.KITKAT)
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_third);
        Bundle b = getIntent().getExtras();
        HashMap<String, Integer> idcid = (HashMap<String, Integer>) b.getSerializable("ArrayCid");
        s = new ArrayList<>(idcid.keySet());
        tmin1 = new ArrayList<>();
        tmin2 = new ArrayList<>();
        tmin3 = new ArrayList<>();
        tmax1 = new ArrayList<>();
        tmax2 = new ArrayList<>();
        tmax3 = new ArrayList<>();
        pre1 = new ArrayList<>();
        pre2 = new ArrayList<>();
        pre3 = new ArrayList<>();
        data = new ArrayList<>();

         for(int i=0; i<s.size();i++) {
             for (Map.Entry<String, Integer> e : idcid.entrySet()) {
                 if (e.getKey().equals(s.get(i))) {
                     id = Integer.toString(e.getValue());
                 }
             }
             String URL3 = ".json";
             String URL1 = "https://api.ipma.pt/open-data/forecast/meteorology/cities/daily/";
             String result = URL1 +id+ URL3;
             ShowData(result);
         }
    }

    private void ShowData(String url1){
        RequestQueue requestQueue = Volley.newRequestQueue(getApplicationContext());
        StringRequest stringRequest = new StringRequest(Request.Method.GET, url1, new Response.Listener<String>() {
            @SuppressLint("SetTextI18n")
            @Override
            public void onResponse(String response) {
                try{
                    JSONObject jsonObject = new JSONObject(response);
                    JSONArray jsonArray = jsonObject.getJSONArray("data");
                    for(int i=0;i<jsonArray.length();i++) {
                        JSONObject temperaturas = jsonArray.getJSONObject(i);
                        if(i==0) {
                            tmin1.add(String.valueOf(temperaturas.getDouble("tMin")));
                            tmax1.add(String.valueOf(temperaturas.getDouble("tMax")));
                            pre1.add(String.valueOf(temperaturas.getDouble("precipitaProb")));
                            data.add((String) temperaturas.get("forecastDate"));
                                                    }
                        if(i==1) {
                            tmin2.add(String.valueOf(temperaturas.getDouble("tMin")));
                            tmax2.add(String.valueOf(temperaturas.getDouble("tMax")));
                            pre2.add(String.valueOf(temperaturas.getDouble("precipitaProb")));
                            data.add((String) temperaturas.get("forecastDate"));
                        }
                        if(i==2) {
                            tmin3.add(String.valueOf(temperaturas.getDouble("tMin")));
                            tmax3.add(String.valueOf(temperaturas.getDouble("tMax")));
                            pre3.add(String.valueOf(temperaturas.getDouble("precipitaProb")));
                            data.add((String) temperaturas.get("forecastDate"));
                        }
                    }
                    if(tmin1.size()==s.size()) {
                        ViewPager();
                    }
                }catch (JSONException e){e.printStackTrace();}
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                error.printStackTrace();
            }
        });
        int socketTimeout = 30000;
        RetryPolicy policy = new DefaultRetryPolicy(socketTimeout, DefaultRetryPolicy.DEFAULT_MAX_RETRIES, DefaultRetryPolicy.DEFAULT_BACKOFF_MULT);
        stringRequest.setRetryPolicy(policy);
        requestQueue.add(stringRequest);
    }

    public void ViewPager(){
        ViewPager viewPager = findViewById(R.id.view_pager);
        ViewPagerAdapter adapter = new ViewPagerAdapter(this, s, tmin1, tmin2, tmin3, tmax1, tmax2, tmax3, pre1,pre2, pre3, data);
        viewPager.setAdapter(adapter);

    }
}




