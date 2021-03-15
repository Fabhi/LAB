package com.gmail.fabhin7.lab3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.GridView;

public class Q1Activity extends AppCompatActivity {
    GridView gridView;
    int[] items = {R.drawable.logo1,
            R.drawable.logo2,
            R.drawable.logo3,
            R.drawable.logo4,
            R.drawable.logo5,
            R.drawable.logo6,
            R.drawable.logo7,
            R.drawable.logo8,
            R.drawable.logo9,
            R.drawable.logo10,
            R.drawable.logo11,
            R.drawable.logo12,
            R.drawable.logo13,
            R.drawable.logo14,
            R.drawable.logo15,
            R.drawable.logo16,
            R.drawable.logo17,
            R.drawable.logo1,
            R.drawable.logo2,
            R.drawable.logo3,
            R.drawable.logo4,
            R.drawable.logo5,
            R.drawable.logo6,
            R.drawable.logo7,
            R.drawable.logo8,
            R.drawable.logo9,
            R.drawable.logo10,
            R.drawable.logo11,
            R.drawable.logo12,
            R.drawable.logo13,
            R.drawable.logo14,
            R.drawable.logo15,
            R.drawable.logo16,
    };
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_q1);

        gridView = findViewById(R.id.grid_view);
        GridAdapter gridAdapter = new GridAdapter(this, items);
        gridView.setAdapter(gridAdapter);

        gridView.setOnItemClickListener((parent, view, position, id) -> {
            Intent intent = new Intent(Q1Activity.this, SelectedActivity.class);
            intent.putExtra("image", items[position]);
            startActivity(intent);
        });
    }
}