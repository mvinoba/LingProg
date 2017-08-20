-- initialising tables --
firstNames = {}
lastNames = {}
fullNames = {}
i = 1
for line in io.lines('nomes.txt') do -- reads line by line
	if (i%2 == 1) then -- verify even/odd	
		table.insert(firstNames, line)
	else
		table.insert(lastNames, line)
	end
	i=i+1
end


for ind, first in ipairs(firstNames) do	-- makes hash from two arrays
	fullNames[first] = lastNames[ind]
end

for key,value in pairs(fullNames) do print(key,value) end
		
	
	
