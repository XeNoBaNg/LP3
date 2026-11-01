// SPDX-License-Identifier: MIT
pragma solidity ^0.8.38;

// Smart contract for a simple bank account
contract BankAccount {

    // Store the balance of each wallet address
    mapping(address => uint) private balances;

    // Function to deposit Ether into the account
    function deposit() public payable {

        // Check that the deposited amount is greater than zero
        require(msg.value > 0, "Deposit amount must be greater than zero");

        // Add deposited Ether to the sender's balance
        balances[msg.sender] += msg.value;
    }

    // Function to withdraw Ether from the account
    function withdraw(uint amount) public {

        // Check that withdrawal amount is greater than zero
        require(amount > 0, "Withdrawal amount must be greater than zero");

        // Check whether the user has sufficient balance
        require(balances[msg.sender] >= amount, "Insufficient balance");

        // Deduct amount before transferring Ether
        balances[msg.sender] -= amount;

        // Transfer Ether to the sender's wallet
        (bool success, ) = payable(msg.sender).call{value: amount}("");

        // Check whether the transfer was successful
        require(success, "Transfer failed");
    }

    // Function to display the user's account balance
    function getBalance() public view returns (uint) {

        // Return balance of the calling wallet address
        return balances[msg.sender];
    }
}
/*
================================================================================
THEORETICAL CONCEPTS, HOW TO RUN & HOW TO EXPLAIN
================================================================================
1. THEORETICAL CONCEPTS:
   - Smart Contract: Self-executing code stored on the Ethereum blockchain that runs
     deterministically on the Ethereum Virtual Machine (EVM).
   - msg.sender & msg.value:
     * msg.sender: The Ethereum address calling the function.
     * msg.value: The amount of Wei sent with the transaction.
   - mapping(address => uint): Key-value store tracking individual account balances.
   - Checks-Effects-Interactions Pattern (Reentrancy Prevention):
     * Checks: require(amount > 0) and require(balances[msg.sender] >= amount).
     * Effects: balances[msg.sender] -= amount (deduct balance BEFORE transferring).
     * Interactions: payable(msg.sender).call{value: amount}("") (transfer Ether).
   - call vs transfer: call{}("") is the recommended standard in Solidity 0.8+ because it
     forwards all remaining gas and handles gas cost changes gracefully.

2. HOW TO RUN (IN REMIX IDE):
   - Open https://remix.ethereum.org/
   - Create BankAccount.sol under contracts/ and paste this code.
   - In "Solidity Compiler" tab, select compiler version 0.8.20+ and click "Compile".
   - In "Deploy & Run Transactions" tab:
     1. Environment: "Remix VM (Cancun)" or "Injected Provider (MetaMask)".
     2. Click "Deploy".
     3. Deposit Ether: Set VALUE (e.g. 1 Ether) above, click the red "deposit" button.
     4. Check Balance: Click the blue "getBalance" button (returns balance in Wei).
     5. Withdraw Ether: Enter amount in Wei in "withdraw" field, click "withdraw".

3. HOW TO EXPLAIN TO THE EXAMINER (30-SECOND VIVA PITCH):
   "Sir/Madam, this smart contract implements a decentralized Bank Account on Ethereum:
   - It maintains private balances using mapping(address => uint) mapping each wallet to its funds.
   - deposit() is marked 'payable' and checks msg.value > 0 to credit Ether to msg.sender.
   - withdraw() securely validates balance with require(), updates state balances[msg.sender] -= amount
     FIRST to prevent Reentrancy attacks, and then uses .call{value: amount}('') to transfer Ether.
   - getBalance() is a 'view' function that reads the caller's balance without consuming gas."

4. COMMON VIVA QUESTIONS:
   Q: What is the 'payable' keyword?
   A: It is a modifier indicating that a function can receive Ether along with the transaction call.
   Q: What is a Reentrancy attack and how is it prevented here?
   A: An attacker recursively calls withdraw() before their balance is zeroed. We prevent this by
      following the Checks-Effects-Interactions pattern (deducting balance before sending Ether).
================================================================================
*/
