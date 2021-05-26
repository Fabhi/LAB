package com.gmail.fabhin7.lab4;

import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.widget.Toast;

import androidx.core.app.NotificationCompat;
import androidx.core.app.NotificationManagerCompat;

public class AlarmPage extends BroadcastReceiver {

    @Override
    public void onReceive(Context context, Intent intent) {
        Toast.makeText(context, "Inside Re", Toast.LENGTH_SHORT).show();
        String CHANNEL_ID = "234";

        NotificationManagerCompat notificationManager = NotificationManagerCompat.from(context);
        NotificationCompat.Builder notif = new NotificationCompat.Builder(context).setContentTitle("Alarm!").setSmallIcon(R.drawable.ic_launcher_foreground);

        Intent nIntent = new Intent(context, A1Activity.class);
        PendingIntent pd = PendingIntent.getActivity(context, 0, nIntent, 0);
        notif.setContentIntent(pd);

        notificationManager.notify(1, notif.build());
    }
}