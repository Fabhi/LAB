package com.gmail.fabhin7.lab4;

import androidx.appcompat.app.AppCompatActivity;
import android.app.AlarmManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.TimePicker;

import java.util.Calendar;

public class A1Activity extends AppCompatActivity {
    Calendar alarmTime = Calendar.getInstance();
    TimePicker timePicker;
    Button button;

    protected void createCalendar(){
        alarmTime.set(Calendar.HOUR_OF_DAY, timePicker.getCurrentHour());
        alarmTime.set(Calendar.MINUTE, timePicker.getCurrentMinute());
        alarmTime.set(Calendar.SECOND, 0);
        alarmTime.set(Calendar.MILLISECOND, 0);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_a1);
        Context context = getApplicationContext();
        timePicker = findViewById(R.id.timepicker);
        button = findViewById(R.id.button);

        button.setOnClickListener( v -> {
            createCalendar();
            AlarmManager alarmManager = (AlarmManager) getSystemService(ALARM_SERVICE);
            PendingIntent pendingIntent = PendingIntent.getBroadcast(context, 0, new Intent(context, AlarmReceiver.class), PendingIntent.FLAG_UPDATE_CURRENT);
            alarmManager.setExact(AlarmManager.RTC_WAKEUP, alarmTime.getTimeInMillis(), pendingIntent);
        });
    }
}