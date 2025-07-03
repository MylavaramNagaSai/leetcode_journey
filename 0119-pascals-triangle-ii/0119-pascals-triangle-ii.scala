object Solution {
    def getRow(rowIndex: Int): List[Int] = {
        var row = List(1)

        for (i <- 1 to rowIndex) {
            row = (0 :: row).lazyZip(row :+ 0).map(_ + _)
        }

        row
    }
}
