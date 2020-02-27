## Message

- Security awareness is crucial
- Use two factor authentication
- The enemy knows the algorithm
- I will graduate in few months
- I shall write secure software
- Never reuse one time pad keys

## Algorithm

Let's define the key used for encryption for one column as k.

Then the result of xoring k with this column will give as char between a & z (A & Z for first column) or space.

so we can try all possible values of k till we find value which makes all characters in this column satisfy this condition.
and then use this k to decrypte the cipher message.

we can try this algorithm many times and each time we change the value of m and get different decryptions.

from this different decryptions we can guess what is the correct Message.
