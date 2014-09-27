   s = exp(-(-10:0.1:10).^2/2.5)' + rand(length(-10:0.1:10),1);
   num_iter = 15;
   delta_t = 1/3;
   kappa = 30;
   option = 2;
   ad = anisodiff1D(s,num_iter,delta_t,kappa,option);
   figure, subplot 121, plot(s), axis([0 200 0 2]), subplot 122, plot(ad), axis([0 200 0 2])