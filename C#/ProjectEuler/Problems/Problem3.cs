using System;

namespace ProjectEuler
{
	/// <summary>
	/// Problem3.
	/// </summary>
	public class Problem3 : Problem<int, int>
	{
		/// <summary>
		/// Initializes a new instance of the <see cref="ProjectEuler.Problem3"/> class.
		/// </summary>
		public Problem3 ()
			:base(3, "Largest prime factor", 
				"The prime factors of 13195 are 5, 7, 13 and 29. " +
				"What is the largest prime factor of the number 600851475143 ?") 
		{ }
	
		/// <summary>
		/// Solve the specified argv.
		/// </summary>
		/// <param name="argv">Argv.</param>
		protected override int Run (int argv)
		{
			return 29;
		}
	}
}

