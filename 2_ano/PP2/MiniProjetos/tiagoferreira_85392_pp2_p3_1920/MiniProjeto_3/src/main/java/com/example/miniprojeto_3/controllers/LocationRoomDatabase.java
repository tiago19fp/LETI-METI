package com.example.miniprojeto_3.controllers;

import android.content.Context;
import android.os.AsyncTask;

import androidx.annotation.NonNull;
import androidx.room.Database;
import androidx.room.Room;
import androidx.room.RoomDatabase;
import androidx.room.TypeConverters;
import androidx.sqlite.db.SupportSQLiteDatabase;

import com.example.miniprojeto_3.converters.Converter;
import com.example.miniprojeto_3.interfaces.LocationDao;
import com.example.miniprojeto_3.models.Forecast;
import com.example.miniprojeto_3.models.Location;

import java.util.ArrayList;

@Database(entities = Location.class, version = 1)
@TypeConverters(Converter.class)
public abstract class LocationRoomDatabase extends RoomDatabase {

    public abstract LocationDao locationDao();

    private static  volatile LocationRoomDatabase locationRoomInstance;

    public static LocationRoomDatabase getDatabase(final Context context){
        if(locationRoomInstance == null){
            synchronized (LocationRoomDatabase.class){
                if(locationRoomInstance == null){
                    locationRoomInstance = Room.databaseBuilder(context.getApplicationContext(),
                                LocationRoomDatabase.class, "location_database")
                                .fallbackToDestructiveMigration()
                                .addCallback(roomCallback)
                                .build();
                }
            }
        }
        return  locationRoomInstance;
    }

    private static RoomDatabase.Callback roomCallback = new RoomDatabase.Callback() {
        @Override
        public void onCreate(@NonNull SupportSQLiteDatabase db) {
            super.onCreate(db);
            new PopulateDbAsyncTask(locationRoomInstance).execute();
        }
    };

    private static class PopulateDbAsyncTask extends AsyncTask<Void, Void, Void> {
        private LocationDao locationDao;

        private PopulateDbAsyncTask( LocationRoomDatabase db) {
            locationDao = db.locationDao();
        }
        @Override
        protected Void doInBackground(Void... voids) {

            ArrayList<Forecast> forecasts = new ArrayList<>();
            Forecast forecast = new Forecast(1,1,1,"s",1,1,1,"s",1,1,"s");
            forecasts.add(forecast);

            locationDao.insert(new Location(0,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(1,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(2,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(3,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(4,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(5,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(6,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(7,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(8,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(9,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(10,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(11,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(12,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(13,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(14,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(15,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(16,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(17,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(18,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(19,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(20,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(21,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(22,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(23,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(24,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(25,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(26,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(27,1,"1",1,1,1,1,"Aveiro",1,forecasts));
            locationDao.insert(new Location(28,1,"1",1,1,1,1,"Aveiro",1,forecasts));

            return null;
        }
    }
}
