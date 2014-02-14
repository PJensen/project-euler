using NUnit.Framework;
using System;
using ProjectEuler;
using System.Linq;
using System.Diagnostics;

namespace ProjectEulerTest
{
	[TestFixture ()]
	public class Problem3Test
	{
		/// <summary>
		/// The problem.
		/// </summary>
		Problem3 problem;

		[SetUp]
		public void Setup()
		{
			problem = new Problem3 ();
			problem.Constraints.Add (new Constraint("\"one minute rule\"", x=>x.SolveTime < TimeSpan.FromMinutes(1)));
			problem.ProblemStarted += (object sender, EventArgs e) => Console.WriteLine("Starting: " + sender.ToString ());
			problem.ProblemStopped += (object sender, EventArgs e) => Console.WriteLine ("Stopped: " + sender.ToString ());;
			problem.ConstraintEvaluationFailed += (object sender, Constraint e) => Assert.Fail (string.Format ("Constraint: {0} failed!", e.Name));
			problem.ConstraintEvaluationSuccess += (object sender, Constraint e) => Console.WriteLine (string.Format ("Constraint: {0} success!", e.Name));
		}

		[Test ()]
		public void RunProblem3 ()
		{
			Assert.AreEqual (29, problem.Solve (13195));
		}
	}
}

