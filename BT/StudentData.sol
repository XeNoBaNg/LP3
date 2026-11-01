// SPDX-License-Identifier: MIT
pragma solidity ^0.8.38;

// Smart contract to store student information
contract StudentData {

    // Structure to store student details
    struct Student {
        uint rollNo;
        string name;
        uint age;
        string department;
    }

    // Dynamic array to store multiple students
    Student[] public students;

    // Event generated when a student is added
    event StudentAdded(uint rollNo, string name);

    // Event generated when fallback function is called
    event FallbackCalled(address sender, uint amount);

    // Function to add a new student
    function addStudent(
        uint _rollNo,
        string memory _name,
        uint _age,
        string memory _department
    ) public {

        require(_rollNo > 0, "Invalid roll number");
        require(_age > 0, "Invalid age");

        students.push(
            Student(_rollNo, _name, _age, _department)
        );

        emit StudentAdded(_rollNo, _name);
    }

    // Function to retrieve student details
    function getStudent(uint index)
        public
        view
        returns (uint, string memory, uint, string memory)
    {
        require(index < students.length, "Student not found");

        Student memory s = students[index];

        return (s.rollNo, s.name, s.age, s.department);
    }

    // Function to get total number of students
    function getStudentCount() public view returns (uint) {
        return students.length;
    }

    // Receive function to accept plain Ether
    receive() external payable {
        emit FallbackCalled(msg.sender, msg.value);
    }

    // Fallback function for unmatched function calls
    fallback() external payable {
        emit FallbackCalled(msg.sender, msg.value);
    }
}
/*
================================================================================
THEORETICAL CONCEPTS, HOW TO RUN & HOW TO EXPLAIN
================================================================================
1. THEORETICAL CONCEPTS:
   - struct: Custom user-defined data type grouping multiple variables (rollNo, name, age, department).
   - Dynamic Array (Student[] public students): Growable on-chain storage for records.
   - Memory vs Storage:
     * storage: Persistent state variables permanently written to the blockchain.
     * memory: Temporary data held in memory during function execution (cheaper gas).
   - Events (emit StudentAdded): Logs emitted into EVM transaction receipts, enabling
     external DApps/frontends (Web3.js/Ethers.js) to listen and react.
   - receive() vs fallback():
     * receive() external payable: Triggered when Ether is sent with empty calldata (msg.data is empty).
     * fallback() external payable: Triggered when no function signature matches, or data is sent with Ether.

2. HOW TO RUN (IN REMIX IDE):
   - Open https://remix.ethereum.org/
   - Create StudentData.sol under contracts/ and paste this code.
   - Compile using Solidity compiler version 0.8.20+.
   - In "Deploy & Run Transactions", click "Deploy".
   - Under Deployed Contracts:
     1. addStudent: Enter rollNo (e.g. 101), name ("John"), age (20), department ("Computer"). Click "transact".
     2. getStudentCount: Click to see total students (e.g. 1).
     3. getStudent: Enter index 0 to view the student record.
     4. Send Ether directly to contract address: FallbackCalled event is emitted in transaction log!

3. HOW TO EXPLAIN TO THE EXAMINER (30-SECOND VIVA PITCH):
   "Sir/Madam, this smart contract demonstrates on-chain data management and fallback handling:
   - We define a struct Student to encapsulate student attributes and store records in a dynamic array.
   - addStudent() validates input with require(), pushes the new struct to the array, and emits
     an indexed event StudentAdded for DApp frontends.
   - getStudent() and getStudentCount() are 'view' functions for reading data with zero gas cost.
   - Finally, receive() and fallback() functions handle unexpected calls and plain Ether transfers,
     emitting FallbackCalled for security and transparency."

4. COMMON VIVA QUESTIONS:
   Q: What is the difference between receive() and fallback()?
   A: receive() is executed when plain Ether is sent with empty msg.data. fallback() is executed when
      a non-existent function is called or Ether is sent with unmatched calldata.
   Q: Why do string parameters require 'memory' keyword?
   A: In Solidity, complex reference types (arrays, structs, strings) require explicit data location
      (memory, storage, or calldata) to specify where the variable should be allocated.
================================================================================
*/
