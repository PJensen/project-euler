using System;
using System.Collections.Generic;
using ProjectEuler.Exceptions;

namespace ProjectEuler
{
	/// <summary>
	/// Problem.
	/// </summary>
	public abstract class Problem<TResult, TParam> : IProblem
		where TResult:  struct
		where TParam: struct
	{
		#region backing store

		/// <summary>
		/// The _dt solving started.
		/// </summary>
		private DateTime _dtSolveStart;

		/// <summary>
		/// The _dt that solving stopped.
		/// </summary>
		private DateTime _dtSolveEnd;

		/// <summary>
		/// The problem is currently _solving.
		/// </summary>
		private volatile bool _solving = false;

		/// <summary>
		/// The _sync root for this instance.
		/// </summary>
		private readonly object _syncRoot = new object();

		/// <summary>
		/// The validate constraints.
		/// </summary>
		bool validateConstraints;

		#endregion

		#region properties

		/// <summary>
		/// Gets the solve time for this problem.
		/// <remarks>if the problem is note currently solving; returns TimeSpan.Zero; 
		/// if the problem is currently solving; returns the current running time; 
		/// if the problem is solved; returns the total running time.</remarks>
		/// </summary>
		/// <value>The solve time.</value>
		public TimeSpan SolveTime 
		{
			get
			{
				if (!_solving && !Solved) { 
					return TimeSpan.Zero;
				} else if (_solving) {
					return DateTime.Now - _dtSolveStart;
				} else {
					return _dtSolveEnd - _dtSolveStart;
				}
			}
		}

		/// <summary>
		/// Gets a value indicating whether this <see cref="ProjectEuler.Problem`2"/> is solved.
		/// </summary>
		/// <value><c>true</c> if solved; otherwise, <c>false</c>.</value>
		public bool Solved { get; private set; }

		/// <summary>
		/// Gets or sets the problem constraints.
		/// </summary>
		/// <value>The problem constraints.</value>
		// public ProblemConstraints Constraints { get; set; }
		public List<Constraint> Constraints { get; set; } 

		#endregion

		/// <summary>
		/// Initializes a new instance of the <see cref="ProjectEuler.Problem"/> class.
		/// </summary>
		/// <param name="number">Number.</param>
		protected Problem (int number, string name, string description, bool validateConstraints = true)
		{
			this.validateConstraints = validateConstraints;
			Constraints = new List<Constraint> ();
			Description = description;
			Number = number;
			Name = name;
		}

		/// <summary>
		/// Gets or sets the description.
		/// </summary>
		/// <value>The description.</value>
		public string Name { get; private set; }

		/// <summary>
		/// Gets the description.
		/// </summary>
		/// <value>The description.</value>
		public string Description { get; private set; }

		/// <summary>
		/// Gets the number.
		/// </summary>
		/// <value>The number.</value>
		public int Number { get; private set; }

		/// <summary>
		/// Solve this instance.
		/// </summary>
		protected abstract TResult Run (TParam argv);

		/// <summary>
		/// Solve this instance.
		/// </summary>
		public TResult Solve(TParam argv)
		{
			if (this.validateConstraints) { 
				ProblemStopped += (object sender, EventArgs e) => {
					foreach(var c in Constraints) { 
						if (c.Validate(this)) { 
							OnConstraintEvaluationSuccess(c);
						} else {
							OnConstraintEvaluationFailed(c);
						}
					}
				};
			}

			TResult result = default(TResult);
			lock (_syncRoot) {
				_dtSolveStart = DateTime.Now;
				_solving = true;
				OnProblemStarted ();
				try {
					result = Run(argv);
					Solved = true;
				} catch (Exception ex) {
					Solved = false;
					throw new ProblemException (string.Format ("failed solving problem {0}", Number), ex);
				} finally {
					_solving = false;
					_dtSolveEnd = DateTime.Now;
					OnProblemStopped ();
				}
			}
			return result;
		}

		/// <summary>
		/// Raises the problem started event.
		/// </summary>
		private void OnProblemStarted()
		{
			if (ProblemStarted != null) {
				ProblemStarted (this, new EventArgs ());
			}
		}

		/// <summary>
		/// Raises the problem stopped event.
		/// </summary>
		private void OnProblemStopped()
		{
			if (ProblemStopped != null) {
				ProblemStopped(this, new EventArgs ());
			}
		}

		/// <summary>
		/// Raises the constraint validated event.
		/// </summary>
		/// <param name="e">E.</param>
		private void OnConstraintEvaluationSuccess(Constraint e) 
		{
			if (ConstraintEvaluationSuccess != null) { 
				ConstraintEvaluationSuccess (this, e);
			}
		}

		/// <summary>
		/// Raises the constraint validated event.
		/// </summary>
		/// <param name="e">E.</param>
		private void OnConstraintEvaluationFailed(Constraint e) 
		{
			if (ConstraintEvaluationFailed != null) { 
				ConstraintEvaluationFailed (this, e);
			}
		}

		/// <summary>
		/// Occurs when problem started.
		/// </summary>
		public event EventHandler ProblemStarted;

		/// <summary>
		/// Occurs when problem stopped.
		/// </summary>
		public event EventHandler ProblemStopped;

		/// <summary>
		/// Occurs when a constraint is successfully evaluated.
		/// </summary>
		public event EventHandler<Constraint> ConstraintEvaluationSuccess;

		/// <summary>
		/// Occurs when constraint evaluation failed.
		/// </summary>
		public event EventHandler<Constraint> ConstraintEvaluationFailed;

		/// <summary>
		/// Returns a <see cref="System.String"/> that represents the current <see cref="ProjectEuler.Problem`2"/>.
		/// </summary>
		/// <returns>A <see cref="System.String"/> that represents the current <see cref="ProjectEuler.Problem`2"/>.</returns>
		public override string ToString ()
		{
			return string.Format ("[Problem: SolveTime={0}, Solved={1}, Name={2}, Number={3}]", SolveTime, Solved, Name, Number);
		}
	}


}

