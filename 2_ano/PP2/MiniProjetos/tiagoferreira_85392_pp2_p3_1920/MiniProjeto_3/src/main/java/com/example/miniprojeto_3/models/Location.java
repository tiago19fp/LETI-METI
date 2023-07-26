package com.example.miniprojeto_3.models;

import androidx.room.Entity;
import androidx.room.PrimaryKey;

import java.util.List;

@Entity(tableName = "location_table")
public class Location {

    @PrimaryKey()
    private int id;
    private int idRegiao;
    private String idAreaAviso;
    private int idConcelho;
    private int globalIdLocal;
    private double latitude;
    private int idDistrito;
    private String local;
    private double longitude;
    private List<Forecast> forecasts;

    public Location(int id, int idRegiao, String idAreaAviso, int idConcelho, int globalIdLocal, double latitude, int idDistrito, String local, double longitude, List<Forecast> forecasts) {
        this.id = id;
        this.idRegiao = idRegiao;
        this.idAreaAviso = idAreaAviso;
        this.idConcelho = idConcelho;
        this.globalIdLocal = globalIdLocal;
        this.latitude = latitude;
        this.idDistrito = idDistrito;
        this.local = local;
        this.longitude = longitude;
        this.forecasts = forecasts;
    }

    public int getId(){
        return id;
    }

    public int getIdRegiao() {
        return idRegiao;
    }

    public String getIdAreaAviso() {
        return idAreaAviso;
    }

    public int getIdConcelho() {
        return idConcelho;
    }

    public int getGlobalIdLocal() {
        return globalIdLocal;
    }

    public double getLatitude() {
        return latitude;
    }

    public int getIdDistrito() {
        return idDistrito;
    }

    public String getLocal() {
        return local;
    }

    public double getLongitude() {
        return longitude;
    }

    public List<Forecast> getForecasts() {
        return forecasts;
    }

    @Override
    public String toString() {
        return "Location{" +
                "id=" + id +
                ", idRegiao=" + idRegiao +
                ", idAreaAviso='" + idAreaAviso + '\'' +
                ", idConcelho=" + idConcelho +
                ", globalIdLocal=" + globalIdLocal +
                ", latitude=" + latitude +
                ", idDistrito=" + idDistrito +
                ", local='" + local + '\'' +
                ", longitude=" + longitude +
                ", forecasts=" + forecasts +
                '}';
    }
}
