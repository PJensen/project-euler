using System;
using System.Collections.Generic;

namespace ProjectEuler
{
	/// <summary>
	/// Problem interface.
	/// </summary>
	public interface IProblem
	{
		/// <summary>
		/// Gets the solve time.
		/// </summary>
		/// <value>The solve time.</value>
		TimeSpan SolveTime { get; }

		/// <summary>
		/// Gets the name.
		/// </summary>
		/// <value>The name.</value>
		string Name { get; }

		/// <summary>
		/// Gets the number.
		/// </summary>
		/// <value>The number.</value>
		int Number { get; }

		/// <summary>
		/// Gets the description.
		/// </summary>
		/// <value>The description.</value>
		string Description { get; }

		/// <summary>
		/// Gets or sets the constraints.
		/// </summary>
		/// <value>The constraints.</value>
		List<Constraint> Constraints { get; set; } 

		/// <summary>
		/// Occurs when problem started.
		/// </summary>
		event EventHandler ProblemStarted;

		/// <summary>
		/// Occurs when problem stopped.
		/// </summary>
		event EventHandler ProblemStopped;

		/// <summary>
		/// Occurs when a constraint is successfully evaluated.
		/// </summary>
		event EventHandler<Constraint> ConstraintEvaluationSuccess;

		/// <summary>
		/// Occurs when constraint evaluation failed.
		/// </summary>
		event EventHandler<Constraint> ConstraintEvaluationFailed;
	}

}
