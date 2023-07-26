package com.example.miniprojeto_3.converters;

import androidx.room.TypeConverter;

import com.example.miniprojeto_3.models.Forecast;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.lang.reflect.Type;
import java.util.List;

public class Converter {

    @TypeConverter
    public String fromOptionValuesList(List<Forecast> forecasts) {
        if (forecasts == null) {
            return (null);
        }
        Gson gson = new Gson();
        Type type = new TypeToken<List<Forecast>>() {
        }.getType();
        return gson.toJson(forecasts, type);
    }

    @TypeConverter
    public List<Forecast> toOptionValuesList(String optionValuesString) {
        if (optionValuesString == null) {
            return (null);
        }
        Gson gson = new Gson();
        Type type = new TypeToken<List<Forecast>>() {
        }.getType();
        return gson.fromJson(optionValuesString, type);
    }
}
