require('dotenv').config();

const express = require('express');
const app = express();

const port = process.env.PORT || 5000;

const CronJob = require('cron').CronJob;

const needle = require('needle');

const ip_address = process.env.IP_ADDRESS;

function toggleLights(state) {
  needle.get(ip_address + '/lights_' + state, function(err, resp) {
    if (err) console.log(err);
  });
}

app.listen(port, function() {
  console.log('Listening on port: ' + port);
});

const lightsOnMorning = new CronJob({
  cronTime: '00 30 06 * * 1-7',
  onTick: function() {
    // Lights on every day at 6:30:00 AM
    toggleLights('on');
  },
  start: true,
  timeZone: 'America/New_York'
});

const lightsOffEvening = new CronJob({
  cronTime: '00 30 23 * * 1-7',
  onTick: function() {
    // Lights off every day at 11:30:00 PM
    toggleLights('off');
  },
  start: true,
  timeZone: 'America/New_York'
});

const lightsOffMorningWeekday = new CronJob({
  cronTime: '00 30 09 * * 1-5',
  onTick: function() {
    // Weekdays, lights off at 9:30:00 AM.
    toggleLights('off');
  },
  start: true,
  timeZone: 'America/New_York'
});

const lightsOnEveningWeekday = new CronJob({
  cronTime: '00 30 18 * * 1-5',
  onTick: function() {
    // Weekdays, lights on at 6:30:00 PM.
    toggleLights('on');
  },
  start: true,
  timeZone: 'America/New_York'
});
