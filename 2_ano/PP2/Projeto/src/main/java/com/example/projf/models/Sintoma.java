package com.example.projf.models;

import com.google.gson.annotations.SerializedName;

public class Sintoma {
    @SerializedName("Sintoma")
    private String sintoma;

    public Sintoma(String sintoma) {
        this.sintoma = sintoma;
    }

    public String getSintoma() {
        return sintoma;
    }
}
