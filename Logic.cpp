
/*********************************************************************
 verifySolution
 
 Use: This method determines if the Sudoku solution is valid or not.
 It should return a Boolean value - true if the Sudoku grid array 
 contains a valid solution, false if not. This method searches rows,
 columns, and 3x3 grids to ensure that none has a repeated number.
 
 Parameters: none.
 
 Returns: true or false boolean depending on if an error was detected
 on the Sudoku grid.
 
 ********************************************************************/
bool Verifier::verifySolution()
{
	int i, j, x, y;		// Initialize counter variables.
	
	// Searches rows for duplicates.
	for(i = 0; i < 9; i++)	// Increment across y-axis.
	{
		setBoolsFalse();	// After each row is checked, clear all the
							// flag values so that all are false in
							// preparation to begin evaluating next row.
							
		for(j = 0; j < 9; j++)	// Increment across x-axis.
		{	
			// Pass the current grid value to the switcher function so
			// it can check if this value has already occured in the
			// current row.  If it has, return false because this 
			// Sudoku configuration is invalid. If not, keep evaluating.
			if(switcher(i, j) == false)	
				{return false;}		// Return false if duplicate found.
		}
	}
	
	// Searches columns for duplicates.
	for(j = 0; j < 9; j++)	// Increment across x-axis.
	{
		setBoolsFalse();	// After each column checks, clear all the
							// flag values so that all are false in
							// preparation to begin checking next column.
							
		for(i = 0; i < 9; i++)	// Increment across y-axis.
		{
			// Pass the current grid value to the switcher function so
			// it can check if this value has already occured in the
			// current row.  If it has, return false because this 
			// Sudoku configuration is invalid. If not, keep evaluating.
			if(switcher(i, j) == false)
				{return false;}		// Return false if duplicate found.
		}
	}

	// Searches 3x3 subgrids for duplicates.  Subgrids can be thought
	// of as a 3x3 array of 3x3 elements. So, x and y keep track of
	// which subgrid the verifier is checking while i and j keep track
	// of the relative position within that subgrid.
	for(x = 0; x < 3; x++)	// Increments the subgrid subscript along
							// the x-axis.
	{
		for(y = 0; y < 3; y++)	// Increments the subgrid subscript
								// along the y-axis.
		{
			setBoolsFalse();	// Clear the flags from the previously
								// evaluated subgrid.
			
			// Increments the relative position along the x-axis within
			// the x-th y-th (x,y) subgrid.
			for(j = (3*x); j < (3*x + 3); j++)
			{
				// Increments the relative position along the y-axis 
				// within the x-th y-th (x,y) subgrid.
				for(i = (3*y); i < (3*y + 3); i++)
				{
					// For the current element, check to see if it's
					// value duplicates any previous value within the 
					// subgrid.  If so, return false.  This is an
					// invalid Sudoku board.  If not, keep evaluating.
					if(switcher(i, j) == false)
						{return false;}	// Return false if duplicate
				}						// is found.
			}
		}
	}
	return true;	// Return true if none of the test cases have
}					// returned false. THis is a valid Sudoku layout.
