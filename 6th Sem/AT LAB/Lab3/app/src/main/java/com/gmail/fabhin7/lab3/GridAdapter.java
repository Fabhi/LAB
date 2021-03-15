package com.gmail.fabhin7.lab3;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;

class GridAdapter extends BaseAdapter {
    private static int[] items;
    LayoutInflater inflater;

    public GridAdapter(Context appCtx, int[] items){
        inflater = LayoutInflater.from(appCtx);
        GridAdapter.items = items;
    }


    @Override
    public int getCount() {
        return items.length;
    }

    @Override
    public Object getItem(int position) {
        return null;
    }

    @Override
    public long getItemId(int position) {
        return 0;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        convertView = inflater.inflate(R.layout.grid_item, null);
        ImageView icon = convertView.findViewById(R.id.icon);
        icon.setImageResource(items[position]);
        return convertView;
    }
}
