<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Parallel Programming Lab - ISL77</title>
    <style>
        body { font-family: Arial, sans-serif; }
        table { width: 100%; border-collapse: collapse; }
        th, td { padding: 8px; text-align: left; border-bottom: 1px solid #ddd; }
        th { background-color: #f2f2f2; }
        code.bash { background-color: #f4f4f4; padding: 2px; }
    </style>
</head>
<body>
    <h1>Parallel Programming Lab - ISL77</h1>
    <h2>Part A: OpenMP Programs</h2>
    <ol>
        <li>Sort an array of <i>n</i> elements using both sequential and parallel merge sort (using Section). Record the difference in execution time.</li>
        <li>Estimate the value of pi using <p>π = 4 ∑<sub>k=0</sub><sup>∞</sup> (-1)<sup>k</sup> / (2k + 1)</p> parallel programming. Record both serial and parallel execution times.</li>
        <li>Write an OpenMP program that divides the iterations into chunks containing 2 iterations (OMP_SCHEDULE=static,2). Output which iterations of a parallelized for loop are executed by which thread.</li>
        <li>Calculate <i>n</i> Fibonacci numbers using Parallel Directive. Eliminate the race condition using Schedule directive.</li>
        <li>Find the prime numbers from 1 to <i>n</i> using parallel for directive. Record both serial and parallel execution times.</li>
        <li>Parallel Vector Addition</li>
        <li>Calculate the sum of the first 100 numbers using the critical directive.</li>
    </ol>
    <h2>Part B: MPI Programs</h2>
    <ol>
        <li>Demonstration of MPI_Send and MPI_Recv</li>
        <li>Demonstration of deadlock using point to point communication</li>
        <li>Avoidance of deadlock by altering the call sequence</li>
        <li>Avoidance of deadlock by non-blocking calls</li>
        <li>Avoidance of deadlock by using MPI_Sendrecv (Bandwidth also)</li>
        <li>Demonstration of synchronization between the two phases of program</li>
        <li>Demonstration of Broadcast operation</li>
        <li>Demonstration of MPI_Gather</li>
        <li>Demonstration of MPI_Scatter</li>
        <li>Demonstration of MPI_Scatter and MPI_Gather</li>
        <li>Demonstration of MPI_Reduce (MPI_MAX, MPI_MIN, MPI_SUM, MPI_PROD)</li>
        <li>Demonstration of MPI_Allreduce (MPI_MAX, MPI_MIN, MPI_SUM, MPI_PROD)</li>
    </ol>
    <h3>Marks Distribution:</h3>
    <p>Students have to execute 2 programs.</p>
    <table border="1">
        <thead>
            <tr>
                <th></th>
                <th>Part A</th>
                <th>Part B</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>Write up</td>
                <td>4</td>
                <td>4</td>
            </tr>
            <tr>
                <td>Execution</td>
                <td>17</td>
                <td>17</td>
            </tr>
            <tr>
                <td>MCQ</td>
                <td colspan="2">8</td>
            </tr>
        </tbody>
    </table>
    <p><strong>Change of Program:</strong> -4 marks/part</p>
    <h3>To Compile and Execute in Terminal:</h3>
    <p>Compile the program:</p>
    <pre><code class="bash">gcc &lt;your_program&gt;.c -fopenmp</code></pre>
    <p>This will produce an executable named <code>a.out</code>.</p>
    <p>To run the compiled program:</p>
    <pre><code class="bash">./a.out</code></pre>
</body>
</html>
