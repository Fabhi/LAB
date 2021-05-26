package com.gmail.fabhin7.lab3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        findViewById(R.id.first).setOnClickListener(v -> startActivity(new Intent(getApplicationContext(), EvalActivity.class)));
        findViewById(R.id.second).setOnClickListener(v -> startActivity(new Intent(getApplicationContext(), Q1Activity.class)));
        findViewById(R.id.third).setOnClickListener(v -> startActivity(new Intent(getApplicationContext(), Q2Activity.class)));
    }
}