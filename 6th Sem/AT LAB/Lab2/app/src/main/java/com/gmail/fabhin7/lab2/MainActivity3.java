package com.gmail.fabhin7.lab2;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;

public class MainActivity3 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);
        setActivityBackgroundColor(Color.parseColor("#000000"));

        SeekBar red = findViewById(R.id.seek_red),
        green = findViewById(R.id.seek_green),
        blue = findViewById(R.id.seek_blue);
        Button updateButton = findViewById(R.id.update_button);

        updateButton.setOnClickListener(v -> {
            int color = Color.rgb(red.getProgress(),green.getProgress(), blue.getProgress());
            setActivityBackgroundColor(color);
        });
    }

    public void setActivityBackgroundColor(int color) {
        View view = this.getWindow().getDecorView();
        view.setBackgroundColor(color);
    }
}