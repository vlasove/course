""" Quickstart script for InstaPy usage """
# imports
from instapy import InstaPy
from instapy import smart_run

# get an InstaPy session!
session = InstaPy(username="####",
                  password="#####")

with smart_run(session):
    """ Activity flow """
    # general settings
    session.set_dont_include(["friend1", "friend2", "friend3"])

    # activity
    #session.like_by_tags(["python"], amount=100)

    my_followers = session.grab_followers(username="vlasov.evgeny", amount="full", live_match=False, store_locally=True)

    print(my_followers)

    for follower in my_followers:
        some_fol = session.grab_following(username=follower, amount="full", live_match=False, store_locally=True)

        
