x = 0
y = 0
irany = 0

File.open("be.txt", "r") do |file|    
    file.each_char do |c|
        case c
        when "b"
            irany = (irany + 3) % 4
        when 'j'
            irany = (irany + 1) % 4
        when 'e'
            irany = 0
        when 'k'
            irany = 1
        when 'd'
            irany = 2
        when 'n'
            irany = 3
        when /[1-9]/
            lepes = c.to_i
            case irany
            when 0
                y += lepes
            when 1
                x += lepes
            when 2
                y -= lepes
            when 3
                x -= lepes
            end
        end
    end
end

File.open("ki.txt", "w") do |output|
    output.puts(x + y)
end

