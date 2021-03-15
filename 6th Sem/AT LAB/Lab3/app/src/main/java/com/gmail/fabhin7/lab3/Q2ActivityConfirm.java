package com.gmail.fabhin7.lab3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class Q2ActivityConfirm extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_q2_confirm);
        Intent intent = getIntent();
        ((TextView) findViewById(R.id.name_view)).setText(intent.getStringExtra("Name"));
        ((TextView) findViewById(R.id.email_view)).setText(intent.getStringExtra("Email"));
        ((TextView) findViewById(R.id.gender_view)).setText(intent.getStringExtra("Gender"));
        ((TextView) findViewById(R.id.device_view)).setText(intent.getStringExtra("Device"));
        ((TextView) findViewById(R.id.comments_view)).setText(intent.getStringExtra("Comments"));
        ((TextView) findViewById(R.id.rating_view)).setText(intent.getStringExtra("Rating") + "/5.0");
        ((TextView) findViewById(R.id.notified_view)).setText(intent.getStringExtra("Notified"));
    }
}