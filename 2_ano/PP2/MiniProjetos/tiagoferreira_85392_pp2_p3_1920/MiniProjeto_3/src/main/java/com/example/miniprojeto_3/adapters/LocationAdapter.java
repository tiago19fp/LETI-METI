package com.example.miniprojeto_3.adapters;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.miniprojeto_3.R;
import com.example.miniprojeto_3.models.Forecast;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;

public class LocationAdapter extends RecyclerView.Adapter<LocationAdapter.LocationHolder> {
    private ArrayList<Forecast> forecasts = new ArrayList<>();

    @NonNull
    @Override
    public LocationHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View itemView = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.list_item, parent, false);
        return new LocationHolder(itemView);

    }

    @Override
    public void onBindViewHolder(@NonNull LocationHolder holder, int position) {
        Forecast currentForecast = forecasts.get(position);
        holder.data.setText(currentForecast.getForecastDate());
        holder.tMin.setText(String.valueOf(currentForecast.gettMin()));
        holder.tMax.setText(String.valueOf(currentForecast.gettMax()));
        holder.prec.setText(String.valueOf(currentForecast.getPrecipitProb()));
        holder.wind.setText(String.valueOf(currentForecast.getPredWindDir()));
        holder.dataUp.setText(currentForecast.getDataUpdate());

        if(currentForecast.getIdWeatherType()==1){
            holder.estado1.setVisibility(View.VISIBLE);
            holder.estado2.setVisibility(View.GONE);
            holder.estado3.setVisibility(View.GONE);
            holder.estado45.setVisibility(View.GONE);
            holder.estado6.setVisibility(View.GONE);
        }else if(currentForecast.getIdWeatherType()==2){
            holder.estado1.setVisibility(View.GONE);
            holder.estado2.setVisibility(View.VISIBLE);
            holder.estado3.setVisibility(View.GONE);
            holder.estado45.setVisibility(View.GONE);
            holder.estado6.setVisibility(View.GONE);
        }else if(currentForecast.getIdWeatherType()==3){
            holder.estado1.setVisibility(View.GONE);
            holder.estado2.setVisibility(View.GONE);
            holder.estado3.setVisibility(View.VISIBLE);
            holder.estado45.setVisibility(View.GONE);
            holder.estado6.setVisibility(View.GONE);
        }else if(currentForecast.getIdWeatherType()==4 && currentForecast.getIdWeatherType()==5){
            holder.estado1.setVisibility(View.GONE);
            holder.estado2.setVisibility(View.GONE);
            holder.estado3.setVisibility(View.GONE);
            holder.estado45.setVisibility(View.VISIBLE);
            holder.estado6.setVisibility(View.GONE);
        }else if(currentForecast.getIdWeatherType()>=6){
            holder.estado1.setVisibility(View.GONE);
            holder.estado2.setVisibility(View.GONE);
            holder.estado3.setVisibility(View.GONE);
            holder.estado45.setVisibility(View.GONE);
            holder.estado6.setVisibility(View.VISIBLE);
        }


        if(position==0){
            holder.esquerda.setVisibility(View.GONE);
            holder.direita.setVisibility(View.VISIBLE);
        }
        if(forecasts.size()==5) {
            if(position==4) {
                holder.esquerda.setVisibility(View.VISIBLE);
                holder.direita.setVisibility(View.GONE);
            }
        }if(forecasts.size()==4) {
            if(position==3) {
                holder.esquerda.setVisibility(View.VISIBLE);
                holder.direita.setVisibility(View.GONE);
            }
        }if(forecasts.size()==3) {
            if(position==2) {
                holder.esquerda.setVisibility(View.VISIBLE);
                holder.direita.setVisibility(View.GONE);
            }
        }

        if(position==0){
            holder.diaSem.setText("Hoje");
        }

        try {
            Calendar c = Calendar.getInstance();
            c.setTime(new SimpleDateFormat("yyyy-MM-dd").parse(currentForecast.getForecastDate()));
            int dayOfWeek = c.get(Calendar.DAY_OF_WEEK);
            if (dayOfWeek==1 && position!=0) {
                holder.diaSem.setText("Domingo");
            }
            if (dayOfWeek==2 && position!=0) {
                holder.diaSem.setText("Segunda-Feira");
            }
            if (dayOfWeek==3 && position!=0) {
                holder.diaSem.setText("Terça-Feira");
            }
            if (dayOfWeek==4 && position!=0) {
                holder.diaSem.setText("Quarta-Feira");
            }
            if (dayOfWeek==5 && position!=0) {
                holder.diaSem.setText("Quinta-Feira");
            }
            if (dayOfWeek==6 && position!=0) {
                holder.diaSem.setText("Sextra-Feira");
            }
            if (dayOfWeek==7 && position!=0) {
                holder.diaSem.setText("Sábado");
            }
        } catch (ParseException e) {
            e.printStackTrace();
        }

    }

    @Override
    public int getItemCount() {
        return forecasts.size();
    }
    public void setForecasts(ArrayList<Forecast> forecasts) {
        this.forecasts = forecasts;
        notifyDataSetChanged();
    }

    class LocationHolder extends RecyclerView.ViewHolder{
        private TextView data;
        private TextView tMin;
        private TextView tMax;
        private TextView prec;
        private TextView wind;
        private TextView diaSem;
        private TextView dataUp;
        private ImageView windIma;
        private ImageView chuvaIma;
        private ImageView celTmIma;
        private ImageView celtMaIma;
        private ImageView estado1;
        private ImageView estado2;
        private ImageView estado3;
        private ImageView estado45;
        private ImageView estado6;
        private ImageView direita;
        private ImageView esquerda;


        public LocationHolder(@NonNull View itemView) {
            super(itemView);
            data = itemView.findViewById(R.id.data);
            tMin = itemView.findViewById(R.id.tMin);
            tMax = itemView.findViewById(R.id.tMax);
            prec = itemView.findViewById(R.id.prec);
            wind = itemView.findViewById(R.id.wind);
            dataUp = itemView.findViewById(R.id.dataUpdate);
            diaSem = itemView.findViewById(R.id.diaSemana);
            windIma = itemView.findViewById(R.id.windImage);
            chuvaIma = itemView.findViewById(R.id.chuvaPreIma);
            celtMaIma = itemView.findViewById(R.id.celstMaxIma);
            celTmIma = itemView.findViewById(R.id.celstMinIma);
            estado1 = itemView.findViewById(R.id.estado1);
            estado2 = itemView.findViewById(R.id.estado2);
            estado3 = itemView.findViewById(R.id.estado3);
            estado45 = itemView.findViewById(R.id.estado45);
            estado6 = itemView.findViewById(R.id.estado6);
            direita = itemView.findViewById(R.id.setadir);
            esquerda = itemView.findViewById(R.id.setaesq);
        }
    }


}
