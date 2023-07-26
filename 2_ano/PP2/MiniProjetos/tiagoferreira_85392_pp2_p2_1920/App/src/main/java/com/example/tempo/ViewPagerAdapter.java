package com.example.tempo;

import android.annotation.SuppressLint;
import android.content.Context;
import android.os.Build;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.RequiresApi;
import androidx.viewpager.widget.PagerAdapter;


import java.util.ArrayList;


public class ViewPagerAdapter extends PagerAdapter {

    private Context context;
    private ArrayList<String> cids;
    private ArrayList<String> tMin1;
    private ArrayList<String> tMin2;
    private ArrayList<String> tMin3;
    private ArrayList<String> tMax1;
    private ArrayList<String> tMax2;
    private ArrayList<String> tMax3;
    private ArrayList<String> pre1;
    private ArrayList<String> pre2;
    private ArrayList<String> pre3;
    private ArrayList<String> data;

    public ViewPagerAdapter(Context context, ArrayList<String> cids,
                            ArrayList<String> tMin1,ArrayList<String> tMin2,ArrayList<String> tMin3,
                            ArrayList<String> tMax1,ArrayList<String> tMax2,ArrayList<String> tMax3,
                            ArrayList<String> pre1,ArrayList<String> pre2,ArrayList<String> pre3,
                            ArrayList<String> data) {
        this.context = context;
        this.cids = cids;
        this.tMin1 = tMin1;
        this.tMin2 = tMin2;
        this.tMin3 = tMin3;
        this.tMax1 = tMax1;
        this.tMax2 = tMax2;
        this.tMax3 = tMax3;
        this.pre1 = pre1;
        this.pre2 = pre2;
        this.pre3 = pre3;
        this.data = data;

    }

    @Override
    public int getCount() {
        return cids.size();
    }

    @Override
    public boolean isViewFromObject(@NonNull View view, @NonNull Object object) {
        return view == object;
    }

    @SuppressLint("SetTextI18n")
    @NonNull
    @Override
    public Object instantiateItem(@NonNull ViewGroup container, int position) {
        View v = LayoutInflater.from(container.getContext()).inflate(R.layout.paginaview ,container, false);
        TextView textView = v.findViewById(R.id.textview_pagina_viewpager);
        textView.setText(cids.get(position));
        TextView textView2 = v.findViewById(R.id.textview_pagina_tmin);
        textView2.setText(data.get(0)+"\n"+"tMin:"+tMin1.get(position)+"º"+"  tMax:"+tMax1.get(position)+"º"+"  Ppre:"+pre1.get(position)+"%");
        TextView textView3 = v.findViewById(R.id.textview_pagina_tmin2);
        textView3.setText(data.get(1)+"\n"+"tMin:"+tMin2.get(position)+"º"+"  tMax:"+tMax2.get(position)+"º"+"  Ppre:"+pre2.get(position)+"%");
        TextView textView4 = v.findViewById(R.id.textview_pagina_tmin3);
        textView4.setText(data.get(2)+"\n"+"tMin:"+tMin3.get(position)+"º"+"  tMax:"+tMax3.get(position)+"º"+"  Ppre:"+pre3.get(position)+"%");
        container.addView(v);
        return v;
    }

    @Override
    public void destroyItem(@NonNull ViewGroup container, int position, @NonNull Object object) {
        container.removeView((View) object);
    }
}
