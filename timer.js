const express = require('express');
const app = express();

const port = process.env.PORT || 5000;

const CronJob = require('cron').CronJob;

app.listen(port, function() {
  console.log('Listening on port: ' + port);
});

const lightsOnMorning = new CronJob({
  cronTime: '00 30 06 * * 1-7',
  onTick: function() {
    // Lights on every day at 6:30:00 AM
  },
  start: true,
  timeZone: 'America/New_York'
});

const lightsOffEvening = new CronJob({
  cronTime: '00 30 23 * * 1-7',
  onTick: function() {
    // Lights off every day at 11:30:00 PM
  },
  start: true,
  timeZone: 'America/New_York'
});

const lightsOffMorningWeekday = new CronJob({
  cronTime: '00 30 09 * * 1-5',
  onTick: function() {
    // Weekdays, lights off at 9:30:00 AM.
  },
  start: true,
  timeZone: 'America/New_York'
});

const lightsOnEveningWeekday = new CronJob({
  cronTime: '00 30 18 * * 1-5',
  onTick: function() {
    // Weekdays, lights on at 6:30:00 PM.
  },
  start: true,
  timeZone: 'America/New_York'
});
