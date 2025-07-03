defmodule Solution do
  def zigzag_level_order(nil), do: []

  def zigzag_level_order(root) do
    traverse([[root]], [], true)
  end

  defp traverse([], result, _), do: Enum.reverse(result)

  defp traverse([[] | rest], result, direction), do: traverse(rest, result, direction)

  defp traverse([level | rest], result, direction) do
    values = Enum.map(level, & &1.val)

    next_level =
      level
      |> Enum.reduce([], fn node, acc ->
        acc
        |> maybe_add(node.left)
        |> maybe_add(node.right)
      end)
      |> Enum.reject(&is_nil/1)

    values =
      if direction do
        values
      else
        Enum.reverse(values)
      end

    traverse(rest ++ [next_level], [values | result], !direction)
  end

  defp maybe_add(acc, nil), do: acc
  defp maybe_add(acc, node), do: acc ++ [node]
end
