clf;
clear;
close all;

set(0,'DefaultFigureWindowStyle','docked')

%Gamma 2 beta 0
file = 'SQUARE01.CSV';
T = readtable(file);
array = table2array(T);
sz = size(array);
x = array(1:sz(1),1);
y = array(1:sz(1),2);


figure('name', 'gamma = 2, beta = 0');
subplot(2,1,2);
plot(x+5e-04, -(y-2.3)+2.3);
title("Output");
xlabel('Time(s)');
ylabel('Amplitude(volt)');
set(gcf,'color','w');
set(gca,'FontSize',20)
xticks(0:1e-04:25e-04);

%Gamma 2 beta 0
file = 'bus-c.CSV';
T = readtable(file);
array_1 = table2array(T);
sz_1 = size(array_1);
x_1 = array_1(1:sz_1(1),1);
y_1 = array_1(1:sz_1(1),2);
subplot(2,1,1);
plot(x_1+5e-04,y_1);
ylim([758980352 1.4e+09 ]); 
title("i2s data");
xlabel('Time(s)');
ylabel('data value(decimal)');
set(gcf,'color','w');
set(gca,'FontSize',20)
xticks(0:1e-04:25e-04);

