enum AccountState
{
    active,
    frozen,
    closed,
    notVerified
};

void AccountStateController()
{
    auto state = AccountState::closed;
    auto balance = 0.0;
    while (true)
    {
        switch (state)
        {
        case AccountState::closed:
            if(balance > 3000)
            {
                state = AccountState::active;
            }
            else
            {
                state = AccountState::notVerified;
            }
            
            break;
        case AccountState::notVerified:
            if(balance > 3000)
            {
                state = AccountState::active;
            }            
            break;
        case AccountState::active:
            if(balance < -3000)
            {
                state = AccountState::frozen;
            }
            break;
        case AccountState::frozen:
            if(balance > 0)
            {
                state = AccountState::active;
            }
            break;
        
        default:
            break;
        }
    }
    

}