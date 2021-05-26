package com.gmail.fabhin7.lab4;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        findViewById(R.id.first).setOnClickListener(v -> startActivity(new Intent(getApplicationContext(), EvaluationActivity.class)));
        findViewById(R.id.second).setOnClickListener(v -> startActivity(new Intent(getApplicationContext(), Q1Activity.class)));
        findViewById(R.id.third).setOnClickListener(v -> startActivity(new Intent(getApplicationContext(), A1Activity.class)));
    }
}