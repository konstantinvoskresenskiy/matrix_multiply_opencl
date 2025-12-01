<!DOCTYPE html>
<html>
<head>
</head>
<body>
<h1 align="center">🧮 Matrix Multiplication with OpenCL</h1>

<div align="center">
  <strong>High-performance matrix multiplication using OpenCL with CI/CD support</strong>
</div>

<br>

<div align="center">
  <!-- Build Status -->
  <img src="https://img.shields.io/badge/build-passing-brightgreen" alt="Build Status">
  <!-- License -->
  <img src="https://img.shields.io/badge/license-MIT-blue" alt="License">
  <!-- OpenCL -->
  <img src="https://img.shields.io/badge/OpenCL-✅-success" alt="OpenCL Support">
  <!-- CI -->
  <img src="https://img.shields.io/badge/CI-GitHub_Actions-blue" alt="CI">
</div>

<hr>

<h2>📋 Table of Contents</h2>
<ul>
  <li><a href="#features">Features</a></li>
  <li><a href="#requirements">Requirements</a></li>
  <li><a href="#quick-start">Quick Start</a></li>
  <li><a href="#build-instructions">Build Instructions</a></li>
  <li><a href="#testing">Testing</a></li>
  <li><a href="#ci-cd">CI/CD</a></li>
  <li><a href="#project-structure">Project Structure</a></li>
  <li><a href="#license">License</a></li>
</ul>

<h2 id="features">✨ Features</h2>
<table border="1">
  <tr>
    <td><strong>🚀 Performance</strong></td>
    <td>GPU acceleration via OpenCL</td>
  </tr>
  <tr>
    <td><strong>💻 CPU Fallback</strong></td>
    <td>pocl support for CPU execution</td>
  </tr>
  <tr>
    <td><strong>🧪 Testing</strong></td>
    <td>Comprehensive test suite</td>
  </tr>
  <tr>
    <td><strong>🔧 CI/CD</strong></td>
    <td>GitHub Actions with automated testing</td>
  </tr>
  <tr>
    <td><strong>📦 Cross-platform</strong></td>
    <td>Linux, Windows, macOS support</td>
  </tr>
</table>

<h2 id="requirements">📦 Requirements</h2>
<ul>
  <li>CMake ≥ 3.10</li>
  <li>C++11 compatible compiler</li>
  <li>OpenCL 1.2+ (or pocl for CPU)</li>
</ul>

<h2 id="quick-start">⚡ Quick Start</h2>

<h3>Ubuntu/Debian:</h3>
<pre><code>sudo apt-get update
sudo apt-get install -y pocl-opencl-icd cmake build-essential
</code></pre>

<h3>Build & Run:</h3>
<pre><code>git clone https://github.com/your-username/matrix-multiply-opencl
cd matrix-multiply-opencl
mkdir build && cd build
cmake .. && make
./test_opencl
</code></pre>

<h2 id="build-instructions">🔨 Build Instructions</h2>

<h3>1. Configure:</h3>
<pre><code>cmake -B build -S .</code></pre>

<h3>2. Build:</h3>
<pre><code>cmake --build build</code></pre>

<h3>3. Install (optional):</h3>
<pre><code>sudo cmake --install build</code></pre>

<h2 id="testing">🧪 Testing</h2>

<h3>Run all tests:</h3>
<pre><code>cd build
./test_basic    # Basic functionality tests
./test_opencl   # OpenCL implementation tests
</code></pre>

<h3>Test example:</h3>
<pre><code>Matrix A = [[1, 2],    Matrix B = [[5, 6],    Result = [[19, 22],
            [3, 4]]                [7, 8]]               [43, 50]]
</code></pre>

<h2 id="ci-cd">🔄 CI/CD</h2>
<p>This project uses GitHub Actions for continuous integration:</p>
<ul>
  <li>✅ Automated builds on Ubuntu</li>
  <li>✅ Unit testing with pocl</li>
  <li>✅ Code formatting checks</li>
  <li>✅ Matrix dimension validation</li>
</ul>

<h2 id="project-structure">📁 Project Structure</h2>
<pre>
matrix-multiply-opencl/
├── .github/workflows/
│   └── ci.yml              # GitHub Actions CI
├── include/
│   └── matrix_multiply.h   # Public API
├── src/
│   └── matrix_multiply.cpp # Implementation
├── kernels/
│   └── matrix_multiply.cl  # OpenCL kernel
├── tests/
│   ├── test_basic.cpp      # Basic tests
│   └── test_opencl.cpp     # OpenCL tests
├── CMakeLists.txt          # Build configuration
├── LICENSE                 # MIT License
└── README.md              # This file
</pre>

<h2 id="license">📄 License</h2>
<p>This project is licensed under the MIT License - see the <a href="LICENSE">LICENSE</a> file for details.</p>

<hr>

<div align="center">
  <p><em>Built with  using OpenCL and modern C++</em></p>
</div>

</body>
</html>
