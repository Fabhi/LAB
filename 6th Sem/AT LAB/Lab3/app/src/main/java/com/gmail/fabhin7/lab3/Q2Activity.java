package com.gmail.fabhin7.lab3;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.RatingBar;
import android.widget.Switch;

import com.google.android.material.slider.Slider;

public class Q2Activity extends AppCompatActivity {

    String name, email, gender, comments, rating, notified, device="";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_q2);

        findViewById(R.id.validate_button).setOnClickListener(v -> {
            name = ((EditText)findViewById(R.id.name_edit)).getText().toString();
            email = ((EditText)findViewById(R.id.email_edit)).getText().toString();
            RadioGroup rg = (RadioGroup)findViewById(R.id.gender);
            gender = ((RadioButton)findViewById(rg.getCheckedRadioButtonId())).getText().toString();
            device += ((CheckBox)findViewById(R.id.androidCheck)).isChecked() ? "Android " : "";
            device += ((CheckBox)findViewById(R.id.iPhoneCheck)).isChecked() ? "Iphone " : "";
            device += ((CheckBox)findViewById(R.id.otherCheck)).isChecked() ? "Others" : "";
            comments = ((EditText) findViewById(R.id.comments)).getText().toString();
            rating = String.valueOf(((RatingBar) findViewById(R.id.rating_bar)).getRating());
            notified = String.valueOf(((Switch) findViewById(R.id.registered)).isChecked());


            Intent intent = new Intent(Q2Activity.this, Q2ActivityConfirm.class);
            intent.putExtra("Name", name);
            intent.putExtra("Email", email);
            intent.putExtra("Gender", gender);
            intent.putExtra("Device", device);
            intent.putExtra("Comments", comments);
            intent.putExtra("Rating", rating);
            intent.putExtra("Notified", notified);
            startActivity(intent);
        });

    }
}