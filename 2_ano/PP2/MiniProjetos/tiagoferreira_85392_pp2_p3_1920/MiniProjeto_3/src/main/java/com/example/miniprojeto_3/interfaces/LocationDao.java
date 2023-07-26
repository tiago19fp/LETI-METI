package com.example.miniprojeto_3.interfaces;

import androidx.lifecycle.LiveData;
import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Update;

import com.example.miniprojeto_3.models.Location;

import java.util.List;

@Dao
public interface LocationDao {

    @Insert
    void insert(Location location);

    @Update
    void update(Location location);

    @Query("SELECT * FROM location_table WHERE local =:nome")
    LiveData<Location> getLocation(String nome);

    @Query("SELECT * FROM location_table ")
    LiveData<List<Location>> getAllLocations();
}
