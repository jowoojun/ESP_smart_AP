import React, {PureComponent} from 'react';

class ChangeModeButton extends PureComponent{

    render(){

        return(
            <div className="col-md-3">
                <a className="btn btn-default btn-lg btn-block" role="button" href="advanced_setting.html">고급설정</a>
            </div>
        )
    }
}

export default ChangeModeButton;
