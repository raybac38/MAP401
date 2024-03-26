

function bitmap_out(image, filename)
	file = io.open(filename, "w")

	bitmap_write_header(file)
	bitmap_write_picture_size(file, image["size"])

	bitmap_write_pixels(file, image["size"], image["pixels"])

	io.close(file)


end

function bitmap_write_picture_size(file, size)
	io.output(file)
	io.write(size.x .. " " ..  size.y .. "\n")
end

function bitmap_write_header(file)
	io.output(file)
	io.write("P1\n")
end


function bitmap_write_pixels(file, size, pixels)
	io.output(file)
	
	taille_x = size.x
	taille_y = size.y

	for index_x = 1, taille_x do
	

		for index_y=1, taille_y do
			io.write(pixels[index_x][index_y] .. " ")
		end
		io.write("\n")
	end
		
end

return {bitmap_out = bitmap_out}
