# @param {Integer} num_rows
# @return {Integer[][]}
def generate(num_rows)
  result = []

  (0...num_rows).each do |i|
    row = Array.new(i + 1, 1)
    (1...i).each do |j|
      row[j] = result[i - 1][j - 1] + result[i - 1][j]
    end
    result << row
  end

  result
end
