import React, {PureComponent} from 'react';
import {Link} from 'react-router';

class ChangeModeButton extends PureComponent{

    render(){

        return(
            <div className="col-md-3">
                <Link to='/advance' className="btn btn-default btn-lg btn-block" role="button">고급설정</Link>
            </div>
        )
    }
}

export default ChangeModeButton;
