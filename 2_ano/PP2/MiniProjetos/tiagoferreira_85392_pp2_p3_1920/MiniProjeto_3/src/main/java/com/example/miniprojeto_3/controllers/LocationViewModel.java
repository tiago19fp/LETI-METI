package com.example.miniprojeto_3.controllers;

import android.app.Application;
import android.os.AsyncTask;

import androidx.annotation.NonNull;
import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.LiveData;

import com.example.miniprojeto_3.controllers.LocationRoomDatabase;
import com.example.miniprojeto_3.interfaces.LocationDao;
import com.example.miniprojeto_3.models.Location;

import java.util.List;

public class LocationViewModel extends AndroidViewModel {

    private LocationDao locationDao;
    private LocationRoomDatabase locationRoomDatabase;
    private LiveData<List<Location>> allLocations;


    public LocationViewModel(@NonNull Application application) {
        super(application);

        locationRoomDatabase = LocationRoomDatabase.getDatabase(application);
        locationDao = locationRoomDatabase.locationDao();
        allLocations = locationDao.getAllLocations();
    }

    public void insert(Location location){
        new InsertAsyncTask(locationDao).execute(location);

    }


    public void update(Location location){
        new UpdateAsyncTask(locationDao).execute(location);

    }

    public LiveData<Location> getLocation(String nome){
        return locationDao.getLocation(nome);
    }

    public LiveData<List<Location>> getAllLocations(){
        return allLocations;
    }

    @Override
    protected void onCleared() {
        super.onCleared();
    }

    private class InsertAsyncTask extends AsyncTask<Location, Void, Void>{

        private LocationDao locationDao;

        public InsertAsyncTask(LocationDao locationDao) {
            this.locationDao = locationDao;
        }

        @Override
        protected Void doInBackground(Location... locations) {
            locationDao.update(locations[0]);
            return null;
        }
    }

    private class UpdateAsyncTask extends AsyncTask<Location, Void, Void>{

        private LocationDao locationDao;

        public UpdateAsyncTask(LocationDao locationDao) {
            this.locationDao = locationDao;
        }

        @Override
        protected Void doInBackground(Location... locations) {
            locationDao.update(locations[0]);
            return null;
        }
    }

}
