# Todo list:

### 1) Noise analysis
Take one run with external random trigger and HV OFF, look at the rate per channel, and identify noisy channels. 

Do the same with HV ON and spot differences (if any).

Take one run with cosmics trigger ( scintillators ), and repeat the same analysis.
Compare the time spectra with those you had in the previous random trigger runs. 

Measure the noise in the run with cosmics trigger, removing the signal hits using the time value.

### 2) Event display

Using the run with cosmics trigger, develop a simple event display (with ROOT), in which you show the hits per event, organized per chamber, layer, tube number.

Start using the logical numbers, then transform them into real positions as measured with a ruler

You should see the spatial correlation among the hits, disposed along a track.

You can play a lot with the event display: e.g. identify single tracks, multiple tracks, showers etc...   ( in parallel with the other exercises) 

### 3) Efficiency estimate

Measure the single tube efficiency using the spatial correlation between the tubes 

Scan different values of HV (max value is 3200 V, do not go above that) 

### 4) Analysis of the drift time spectra and calibration

Fit the t0: this corresponds to the start of the time ditribution of the signal hits

Calculate the drift velocity and the r-t relation, from the differential time distribution 

Using the t0 and the r-t relation, convert the drift time in drift radius , and add it to the output tree

Update the event display developed in 2) to also show the drift radius

### 5) Fit the tracks !

Using the tubes positions and the drift radii, develop a pattern recognition to identify the hits on a track

Fit the track separately in each chamber ( track segments )

Measure the single tube spatial resolution

### 6) Tracking studies

Alignment between the three chambers

Study multiple scattering ( compare regions with different materials in between - existing supports or other materials that we can add ) 

Global track fit

### 7) Geant4 simulation of the apparatus

Simulate the detector setup in geant4

Study the gemetrical acceptance

If there is time: develop the digitization and compare to data 












