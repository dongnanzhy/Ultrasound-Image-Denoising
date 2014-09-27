   vol = randn(100,100,100);
   num_iter = 4;
   delta_t = 3/44;
   kappa = 70;
   option = 2;
   voxel_spacing = ones(3,1);
   diff_vol = anisodiff3D(vol, num_iter, delta_t, kappa, option, voxel_spacing);
   figure, subplot 121, imshow(vol(:,:,50),[]), subplot 122, imshow(diff_vol(:,:,50),[])