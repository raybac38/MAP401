

function Dotproduct(a,b)
	return a.x * b.x + a.y * b.y
end

function Norme(a)
	return math.sqrt(a.x * a.x + a.y * a.y)
end

function Difference(a,b)
	c = {}
	c.x = b.x - a.x
	c.y = b.y - a.y
	return c
end

function Distance(a,b)
	c = {}
	c = Difference(a,b)
	return Norme(c)
end




return {Dotproduct = Dotproduct, Norme = Norme, Distance = Distance}
