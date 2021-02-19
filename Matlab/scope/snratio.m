%s/n ratio calculation
clf;
clear;
close all;

set(0,'DefaultFigureWindowStyle','docked')

file = 'snrat01.CSV';
table = readtable(file);
array1 = table2array(table);
signalpeak = array1(1639,2);
noise = array1(1:65536,2);
noise(1636:1643) = -20;
noisemean = mean(noise);
snrat = noisemean-signalpeak;
disp(snrat);

T = readtable(file);
array = table2array(T);
sz = size(array);
x = array(1:sz(1),1);
y = array(1:sz(1),2);
figure('name', 'Signal to noise ratio');

plot(x, y);
ax = gca();
ax.XRuler.Exponent = 3; %set exponent of x axis
title("Signal to noise measurement");
xlabel('Frequency(kHz)');
ylabel('Amplitude(dBmV)');
set(gcf,'color','w');
set(gca,'FontSize',20)
xticks(0:500:20000);
yticks(-100:10:50);
grid on;
hold on
plot(500,25,'*');