package com.example.tempo;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.view.ViewStructure;
import android.widget.Toast;

import com.android.volley.DefaultRetryPolicy;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.RetryPolicy;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class SecondActivity extends AppCompatActivity {

    RecyclerView mRecyclerView;
    RecyclerView.LayoutManager mLayoutManager;
    RecylcarAdapter mAdapter;
    HashMap<String,Integer>idCids;
    ArrayList<String> array;
    FloatingActionButton fl;
    HashMap<String, Integer> idCids3;

    @SuppressLint("WrongViewCast")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        Bundle b = getIntent().getExtras();
        idCids = (HashMap<String,Integer>) b.getSerializable("ArrayCids");
        array = new ArrayList<String>(idCids.keySet());
        idCids3 = new HashMap<String, Integer>();
        mRecycler();

        mAdapter.setOnItemClickListener(new RecylcarAdapter.OnItemClickListener() {
            @RequiresApi(api = Build.VERSION_CODES.KITKAT)
            @Override
            public void onItemClick(int position) {
                //array3.add(array.get(position));
                for(Map.Entry<String,Integer> e : idCids.entrySet()) {
                    if (e.getKey().equals(array.get(position))){
                         idCids3.put(array.get(position),e.getValue());
                    }
                }
                Toast.makeText(SecondActivity.this, "Cidade Adicionada", Toast.LENGTH_SHORT).show();
            }
        });

        fl = findViewById(R.id.butoon_flo);
        fl.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openThiAct();
            }
        });
    }

    public void openThiAct() {
        Intent intent = new Intent(this, ThirdActivity.class);
        Bundle bundle = new Bundle();
        bundle.putSerializable("ArrayCid", idCids3);
        intent.putExtras(bundle);
        startActivity(intent);
    }

    public void mRecycler(){
        mRecyclerView = findViewById(R.id.recycler_cidade);
        mRecyclerView.setHasFixedSize(true);
        mLayoutManager = new LinearLayoutManager(this);
        mAdapter = new RecylcarAdapter(array);
        mRecyclerView.setLayoutManager(mLayoutManager);
        mRecyclerView.setAdapter(mAdapter);
    }
}