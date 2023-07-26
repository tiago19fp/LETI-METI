package com.example.miniprojeto_3.models;

public class Forecast {
    private double precipitProb;
    private double tMin;
    private double tMax;
    private String predWindDir;
    private int idWeatherType;
    private int classWindSpeed;
    private double longitude;
    private String forecastDate;
    private int classPrecInt;
    private double latitude;
    private String dataUpdate;

    public Forecast(double precipitProb, double tMin, double tMax, String predWindDir, int idWeatherType, int classWindSpeed, double longitude, String forecastDate, int classPrecInt, double latitude, String dataUpdate) {
        this.precipitProb = precipitProb;
        this.tMin = tMin;
        this.tMax = tMax;
        this.predWindDir = predWindDir;
        this.idWeatherType = idWeatherType;
        this.classWindSpeed = classWindSpeed;
        this.longitude = longitude;
        this.forecastDate = forecastDate;
        this.classPrecInt = classPrecInt;
        this.latitude = latitude;
        this.dataUpdate = dataUpdate;
    }

    public double getPrecipitProb() {
        return precipitProb;
    }

    public double gettMin() {
        return tMin;
    }

    public double gettMax() {
        return tMax;
    }

    public String getPredWindDir() {
        return predWindDir;
    }

    public int getIdWeatherType() {
        return idWeatherType;
    }

    public int getClassWindSpeed() {
        return classWindSpeed;
    }

    public double getLongitude() {
        return longitude;
    }

    public String getForecastDate() {
        return forecastDate;
    }

    public int getClassPrecInt() {
        return classPrecInt;
    }

    public double getLatitude() {
        return latitude;
    }

    public String getDataUpdate() {
        return dataUpdate;
    }

    @Override
    public String toString() {
        return "Forecast{" +
                "precipitProb=" + precipitProb +
                ", tMin=" + tMin +
                ", tMax=" + tMax +
                ", predWindDir='" + predWindDir + '\'' +
                ", idWeatherType=" + idWeatherType +
                ", classWindSpeed=" + classWindSpeed +
                ", longitude=" + longitude +
                ", forecastDate='" + forecastDate + '\'' +
                ", classPrecInt=" + classPrecInt +
                ", latitude=" + latitude +
                ", dataUpdate='" + dataUpdate + '\'' +
                '}';
    }
}
