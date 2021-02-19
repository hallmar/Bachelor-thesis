clf;
clear;
close all;

set(0,'DefaultFigureWindowStyle','docked')

%Gamma 2 beta 0
file = 'filt.CSV';
T = readtable(file);
array = table2array(T);
sz = size(array);
x = array(1:sz(1),1);
y = array(1:sz(1),2);


figure('name', 'gamma = 2, beta = 0');
subplot(2,1,1);
plot(x+1.5e-03, y);
title("Output with low pass filter");
xlabel('Time(s)');
ylabel('Amplitude(Volts)');
set(gcf,'color','w');
set(gca,'FontSize',20)

file = 'nofilt.CSV';
T = readtable(file);
array = table2array(T);
sz = size(array);
x = array(1:sz(1),1);
y = array(1:sz(1),2);


subplot(2,1,2);
plot(x+1.5e-03, y);
title("Output without low pass filter");
xlabel('Time(s)');
ylabel('Amplitude(Volts)');
set(gcf,'color','w');
set(gca,'FontSize',20)