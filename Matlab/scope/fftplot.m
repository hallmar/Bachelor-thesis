clf;
clear;
close all;

set(0,'DefaultFigureWindowStyle','docked')

%Gamma 2 beta 0
file = 'g5b5.CSV';
T = readtable(file);
array = table2array(T);
sz = size(array);
x = array(1:sz(1),1);
y = array(1:sz(1),2);
figure('name', 'gamma = 2, beta = 0');

subplot(2,1,2);
plot(x, y);
ax = gca();
ax.XRuler.Exponent = 3; %set exponent of x axis
title("Frequency domain(FFT) of op1(t)");
xlabel('Frequency(kHz)');
ylabel('Amplitude(dBmV)');
set(gcf,'color','w');
set(gca,'FontSize',20)
xticks(0:500:14000);
yticks(-100:10:50);
grid on;

wavefile = 'g5b5WAVE.CSV';
table = readtable(wavefile);
array = table2array(table);
sz1 = size(array);
x_1 = array(1:sz1(1)/2,1);
y_1 = array(1:sz1(1)/2,2);

subplot(2,1,1);
plot(x_1+3e-03,y_1,'LineWidth',2);
title("op1(t)");
xlabel('Time(s)');
ylabel('Amplitude(v)');
set(gcf,'color','w');
set(gca,'FontSize',20)
ylim([-8 8]);
yticks(-8:1:8);

%g2 d4
%g3 d6
%g5 d1





