package com.example.projf.models;

import com.google.gson.annotations.SerializedName;

public class User {

    @SerializedName("_id")
    private String id;
    @SerializedName("Name")
    private String nome;
    @SerializedName("Email")
    private String email;
    @SerializedName("Sintomas")
    private String sintomas;
    @SerializedName("EstadoSaude")
    private String estadoSaude;
    @SerializedName("Latitude")
    private String latitude;
    @SerializedName("Longitude")
    private String longitude;
    @SerializedName("Idade")
    private String idade;
    @SerializedName("Sexo")
    private String sexo;

    public User(String nome, String email, String sintomas, String estadoSaude, String latitude, String longitude, String idade, String sexo) {
        this.nome = nome;
        this.email = email;
        this.sintomas = sintomas;
        this.estadoSaude = estadoSaude;
        this.latitude = latitude;
        this.longitude = longitude;
        this.idade = idade;
        this.sexo = sexo;
    }

    public String getId() {
        return id;
    }

    public String getNome() {
        return nome;
    }

    public String getEmail() {
        return email;
    }

    public String getSintomas() {
        return sintomas;
    }

    public String getEstadoSaude() {
        return estadoSaude;
    }

    public String getLatitude() {
        return latitude;
    }

    public String getLongitude() {
        return longitude;
    }

    public String getIdade() {
        return idade;
    }

    public String getSexo() {
        return sexo;
    }

    public void setEstadoSaude(String estadoSaude) {
        this.estadoSaude = estadoSaude;
    }
}
