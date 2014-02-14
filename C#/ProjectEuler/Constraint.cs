using System;
using System.Collections.Generic;
using ProjectEuler.Exceptions;

namespace ProjectEuler
{
	/// <summary>
	/// Constraint.
	/// </summary>
	public sealed class Constraint : EventArgs
	{
		#region backing store

		/// <summary>
		/// Gets the name.
		/// </summary>
		/// <value>The name.</value>
		public string Name { get; private set; } 

		/// <summary>
		/// Gets the predicate.
		/// </summary>
		/// <value>The predicate.</value>
		public Predicate<IProblem> Predicate { get; private set; } 

		/// <summary>
		/// Validate the specified problem constraint.
		/// </summary>
		/// <param name="problem">Problem.</param>
		public bool Validate(IProblem problem)
		{
			return Predicate (problem);
		}

		#endregion

		/// <summary>
		/// Initializes a new instance of the <see cref="ProjectEuler.Constraint"/> class.
		/// </summary>
		/// <param name="name">Name.</param>
		/// <param name="predicate">Predicate.</param>
		public Constraint(string name, Predicate<IProblem> predicate)
		{
			if (name == null) throw new ArgumentNullException ("name");
			if (predicate == null) throw new ArgumentNullException ("predicate");

			Predicate = predicate;
			Name = name;
		}
	}
	
}
