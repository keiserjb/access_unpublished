ACCESS UNPUBLISHED 

Description:
------------
This module displays a message when you save a node that is not published.
The message contains the URL to the node with a special hash value. This 
URL can be used to allow access to the node to unauthorised users.

Note that everyone that obtains the correct URL will be able to access the
unpublised node. This method of security through obfuscation should not be
used for websites where security is really an issue. After installing this
module unpublished nodes should be considered more or less public.

Usage:
------
After installing and activating the 'Access unpublished' module you should 
first update the settings for the module.
  admin/settings/access_unpublished
You will need to specify a 'Private key' which will be used to create the
unique hash to access unpublished nodes. If you do not specify a private key
one will be generated when you install the module. You can also change the
value of the 'Query string'. This is the value used in the URL to identify
the generated hash.

Afterwards you will need to set the module permissions
  admin/user/permissions
For each node type available in your website you can activate the ability to
access unpublished nodes. 

Author:
-------
aberg (http://drupal.org/user/341657 http://leiden365.nl/blog)

Code Contributions:
-------------------


Resources used:
---------------
http://drupal.org/node/611918
http://thedrupalblog.com/creating-your-own-node-access-control-layer-using-hook-menu-alter

